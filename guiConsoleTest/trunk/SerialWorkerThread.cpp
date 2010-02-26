/*
 * SerialWorkerThread.cpp
 *
 *  Created on: Feb 25, 2010
 *      Author: dejagerd
 */
#include "SerialWorkerThread.hpp"
	SerialWorkerThread::SerialWorkerThread(const char * dev, unsigned long baud)
             : m_dev(dev), m_baud(baud)
	{}
	SerialWorkerThread::~SerialWorkerThread()
	{
		m_thread.join();
	}

	void SerialWorkerThread::doit()
	{
		boost::asio::io_service io_service;
		// define an instance of the main class of this program
		minicom c(io_service, m_baud,m_dev);
		// run the IO service as a separate thread, so the main thread can block on standard input
		io_service.run();
	}
	void SerialWorkerThread::start()
	{
	    m_thread = boost::thread(&SerialWorkerThread::doit, this);
	}
	void SerialWorkerThread::join()
	{
		m_thread.join();
	}

