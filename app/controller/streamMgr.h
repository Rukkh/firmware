/* 
 * File:   streamMgr.h
 * Author: Blake
 *
 * Created on 22 June 2015, 12:15 AM
 */

#ifndef STREAMMGR_H
#define	STREAMMGR_H

#include "platform.h"

class streamMgr : public Stream 
{
public:
    streamMgr();
   
    int available();
    int read();
    int peek();
    void flush();
    
    void begin();
    size_t write(uint8_t byte);
    
    void arbitrate();
    
    bool tcpStatus();
    
private:
    
    Stream * myStream;
    
    TCPServer myServer = TCPServer(1023);
    TCPClient myClient;   
    
    //Serial is defined in wiring_spark_usbserial.h
    //which is brought in via platform.h/application.h

};

#endif	/* STREAMMGR_H */

