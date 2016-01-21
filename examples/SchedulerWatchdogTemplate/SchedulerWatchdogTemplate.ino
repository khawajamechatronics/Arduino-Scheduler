/**
 * @file SchedulerWatchdogTemplate.ino
 * @version 1.0
 *
 * @section License
 * Copyright (C) Mikael Patel, 2015
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * @section Description
 * This Arduino sketch uses the Scheduler library. A watchdog task
 * that monitors the time to scheduler all tasks. The alarm is called
 * if the cycle is long than 10 ms.
 */

#include <Scheduler.h>
#include "Watchdog.h"

unsigned long count = 0;

void alarm(unsigned long ms)
{
  Serial.print(millis());
  Serial.print(':');
  Serial.print(count);
  Serial.print(F(":watchdog alarm:ms="));
  Serial.println(ms);
  count = 0;
}

Watchdog<10, alarm> watchdog;

void setup()
{
  Serial.begin(57600);
  Serial.println(F("SchedulerWatchdogTemplate: started"));
  Scheduler.start(watchdog.setup, watchdog.loop);
}

void loop()
{
  delayMicroseconds(random(11000));
  yield();
  count += 1;
}


