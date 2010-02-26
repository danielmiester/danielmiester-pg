/* minicom.cpp
 A simple demonstration minicom client with Boost asio

 Parameters:
 baud rate
 serial port (eg /dev/ttyS0 or COM1)

 To end the application, send Ctrl-C on standard input
 */

#include "minicom.hpp"
using namespace std;
minicom::minicom(boost::asio::io_service& io_service,	unsigned int baud, const std::string& device) :
	active_(true), io_service_(io_service), serialPort(io_service, device)
{
	using namespace std;
	if (not serialPort.is_open())
	{
		cerr << "Failed to open serial port\n";
		return;
	}
	boost::asio::serial_port_base::baud_rate baud_option(baud);
	serialPort.set_option(baud_option); // set the baud rate after the port has been opened
	read_start();
}

void minicom::write(const char msg) // pass the write data to the do_write function via the io service in the other thread
{
	io_service_.post(boost::bind(&minicom::do_write, this, msg));
}

void minicom::close() // call the do_close function via the io service in the other thread
{
	io_service_.post(boost::bind(&minicom::do_close, this,
			boost::system::error_code()));
}

bool minicom::active() // return true if the socket is still active
{
	return active_;
}



void minicom::read_start(void)
{ // Start an asynchronous read and call read_complete when it completes or fails
	serialPort.async_read_some(boost::asio::buffer(read_msg_, max_read_length),
			boost::bind(&minicom::read_complete, this,
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
}

void minicom::read_complete(const boost::system::error_code& error,
		size_t bytes_transferred)
{ // the asynchronous read operation has now completed or failed and returned an error
	if (!error)
	{ // read completed, so process the data
		for (unsigned int i = 0; i < bytes_transferred; i++)
		{
			if ((read_msg_[i] & 0b00001111) == 0)
				cout << endl;
			cout << hex << (unsigned short) read_msg_[i];

		}
		//cout.write(read_msg_, bytes_transferred); // echo to standard output
		read_start(); // start waiting for another asynchronous read again
	}
	else
		do_close(error);
}

void minicom::do_write(const char msg)
{ // callback to handle write call from outside this class
	bool write_in_progress = !minicom::write_msgs_.empty(); // is there anything currently being written?
	minicom::write_msgs_.push_back(msg); // store in write buffer
	if (!write_in_progress) // if nothing is currently being written, then start
		write_start();
}

void minicom::write_start(void)
{ // Start an asynchronous write and call write_complete when it completes or fails
	boost::asio::async_write(serialPort, boost::asio::buffer(
			&minicom::write_msgs_.front(), 1), boost::bind(
			&minicom::write_complete, this,
			boost::asio::placeholders::error));
}

void minicom::write_complete(const boost::system::error_code& error)
{ // the asynchronous read operation has now completed or failed and returned an error
	if (!error)
	{ // write completed, so send next write data
		minicom::write_msgs_.pop_front(); // remove the completed data
		if (!minicom::write_msgs_.empty()) // if there is anthing left to be written
			write_start(); // then start sending the next item in the buffer
	}
	else
		do_close(error);
}

void minicom::do_close(const boost::system::error_code& error)
{ // something has gone wrong, so close the socket & make this object inactive
	if (error == boost::asio::error::operation_aborted) // if this call is the result of a timer cancel()
		return; // ignore it because the connection cancelled the timer
	if (error)
		cerr << "Error: " << error.message() << endl; // show the error message
	else
		cout << "Error: Connection did not succeed.\n";
	cout << "Press Enter to exit\n";
	serialPort.close();
	active_ = false;
}
/*
int main(int argc, char* argv[])
{
	// on Unix POSIX based systems, turn off line buffering of input, so cin.get() returns after every keypress
	// On other systems, you'll need to look for an equivalent
#ifdef POSIX
	termios stored_settings;
	tcgetattr(0, &stored_settings);
	termios new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_lflag &= (~ISIG); // don't automatically handle control-C
	tcsetattr(0, TCSANOW, &new_settings);
#endif
	try
	{
		if (argc != 1)
		{
			cerr << "Usage: minicom <baud> <device>\n";
			return 1;
		}
		boost::asio::io_service io_service;
		// define an instance of the main class of this program
		minicom c(io_service, boost::lexical_cast<unsigned int>(300),"/dev/ttyUSB0");
		// run the IO service as a separate thread, so the main thread can block on standard input
		boost::thread
				t(boost::bind(&boost::asio::io_service::run, &io_service));
		while (c.active()) // check the internal state of the connection to make sure it's still running
		{
			char ch;
			cin.get(ch); // blocking wait for standard input
			if (ch == 3) // ctrl-C to end program
				break;
			c.write(ch);
		}
		c.close(); // close the minicom client connection
		t.join(); // wait for the IO service thread to close
	} catch (exception& e)
	{
		cerr << "Exception: " << e.what() << "\n";
	}
#ifdef POSIX // restore default buffering of standard input
	tcsetattr(0, TCSANOW, &stored_settings);
#endif
	return 0;
}
*/
