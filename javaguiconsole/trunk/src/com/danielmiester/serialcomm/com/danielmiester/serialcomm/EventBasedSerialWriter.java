package com.danielmiester.serialcomm;

import java.io.IOException;
import java.io.OutputStream;

/** */
public class EventBasedSerialWriter implements Runnable 
{
    OutputStream out;
    
    public EventBasedSerialWriter ( OutputStream out )
    {
        this.out = out;
    }
    
    public void run ()
    {
        try
        {                
            int c = 0;
            while ( ( c = System.in.read()) > -1 )
            {
                this.out.write(c);
            }                
        }
        catch ( IOException e )
        {
            e.printStackTrace();
            System.exit(-1);
        }            
    }
}