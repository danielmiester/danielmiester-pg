/*
 * SerialWorkerThread.hpp
 *
 *  Created on: Feb 25, 2010
 *      Author: dejagerd
 */

#ifndef SERIALWORKERTHREAD_HPP_
#define SERIALWORKERTHREAD_HPP_
#include "minicom.hpp"
#include <iostream>
#include <boost/thread.hpp>

class SerialWorkerThread
 {
 public:

    SerialWorkerThread(const char * dev, unsigned long baud);
    ~SerialWorkerThread();

	void start();
	void join();
private:
	void doit();
	const char *	m_dev;
	unsigned int	m_baud;
	boost::thread	m_thread;
};

#endif /* SERIALWORKERTHREAD_HPP_ */
