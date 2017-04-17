
/****************************************************************************
* Copyright (c) 2017, BlueSky software
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright
*   notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
* 3. All advertising materials mentioning features or use of this software
*    must display the following acknowledgement:
*    This product includes software developed by the BlueSky software.
* 4. Neither the name of the <organization> nor the
*    names of its contributors may be used to endorse or promote products
*    derived from this software without specific prior written permission.
* 
* THIS SOFTWARE IS PROVIDED BY BlueSky software ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL BlueSky software BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
****************************************************************************/

/****************************************************
* This class enables you to set timer asynchronically
* period param is always in milliseconds
*****************************************************/

#include "timer.h"

Timer::Timer() {started_ = false;}

void Timer::start(unsigned long period)
{
    if (!started_)
    {
        period_ = period;
        start_time_ = millis();
        started_ = true;
    }
}

/**********************************************
* Override original start time, and start timer
* again
***********************************************/

void Timer::startOver() 
{
    start_time_ = millis();
    if (!started_)
        started_ = true;
}

/**********************************************
* Return true if timer has finished
***********************************************/

bool Timer::finished()
{
    if (started_)
    {
        end_time_ = millis();
        if (end_time_ - start_time_ >= period_)
        {
            started_ = false;
        }
    }
    return !started_;
}

void Timer::reset() {started_ = false;}

void Timer::delay(unsigned int period)
{
  unsigned long start = millis();
  while (millis() - start < period) {};
}