package com.danielmiester.serialcomm;

import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

import java.io.IOException;
import java.io.InputStream;

/**
 * Handles the input coming from the serial port. A new line character
 * is treated as the end of a block in this example. 
 */
public class EventBasedSerialReader implements SerialPortEventListener 
{
    private InputStream in;
    private byte[] buffer = new byte[1024];
    
    public EventBasedSerialReader ( InputStream in )
    {
        this.in = in;
    }
    
    public void serialEvent(SerialPortEvent arg0) {
        int data;
      
        try
        {
            int len = 0;
            while ( ( data = in.read()) > -1 )
            {
                buffer[len++] = (byte) data;
                if ( data == '@' ) {
                	break;
                }

            }
            System.out.println(new String(buffer,0,len));
        }
        catch ( IOException e )
        {
            e.printStackTrace();
            System.exit(-1);
        }             
    }

}