/*
 * minicom.hpp
 *
 *  Created on: Feb 24, 2010
 *      Author: dejagerd
 */

#ifndef MINICOM_HPP_
#define MINICOM_HPP_
#include <deque>
#include <iostream>
#include <iomanip>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#ifdef POSIX
#include <termios.h>
#endif
using namespace std;
class minicom
{
public:
	minicom(boost::asio::io_service& io_service,unsigned int baud, const string& device);
	void write(const char msg);
	void close();
	bool active();
	static const int max_read_length = 512;
	void do_write(const char msg);
	void write_start(void);

	void read_start(void);
	void read_complete(const boost::system::error_code& error, size_t bytes_transferred);
	void write_complete(const boost::system::error_code& error);
	void do_close(const boost::system::error_code& error);
	bool active_; // remains true while this object is still operating
	boost::asio::io_service& io_service_; // the main IO service that runs this connection
	boost::asio::serial_port serialPort; // the serial port this instance is connected to
	char read_msg_[max_read_length]; // data read from the socket
	deque<char> write_msgs_; // buffered write data
};

#endif /* MINICOM_HPP_ */
