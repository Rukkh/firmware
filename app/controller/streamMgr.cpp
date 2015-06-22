/* 
 * File:   streamMgr.cpp
 * Author: Blake
 * 
 * Created on 22 June 2015, 12:15 AM
 */

#include "streamMgr.h"
#include "Platform.h"

streamMgr::streamMgr() 
{
    //Default to Serial
    myStream = &Serial;
}

void streamMgr::begin()
{
    Serial.begin(57600);
   
    WiFi.on();
    
    if (WiFi.hasCredentials())
    { 
        WiFi.connect();     
        myServer.begin();
    } else
    {   //If there is no Credentials, don't turn the wifi on.
        WiFi.off();
    }      
}

int streamMgr::available()
{
    return myStream->available();
}

int streamMgr::read()
{
    return myStream->read();
}

int streamMgr::peek()
{
    return myStream->peek();
}

void streamMgr::flush()
{
    myStream->flush();
}

void streamMgr::arbitrate()
{
    if (myClient.connected()) 
    {
        myStream = &myClient;
        
    } else 
    {
        myStream = &Serial;
        
        // if no client is yet connected, check for a new connection
        myClient = myServer.available();
    }
           
    
}


size_t streamMgr::write(uint8_t byte)
{
    return myStream-> write(byte);
}


bool streamMgr::tcpStatus() {
    
    return myClient.connected();
}