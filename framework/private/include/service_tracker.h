/**
 *Licensed to the Apache Software Foundation (ASF) under one
 *or more contributor license agreements.  See the NOTICE file
 *distributed with this work for additional information
 *regarding copyright ownership.  The ASF licenses this file
 *to you under the Apache License, Version 2.0 (the
 *"License"); you may not use this file except in compliance
 *with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing,
 *software distributed under the License is distributed on an
 *"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 *specific language governing permissions and limitations
 *under the License.
 */
/*
 * service_tracker.h
 *
 *  Created on: Apr 20, 2010
 *      Author: alexanderb
 */

#ifndef SERVICE_TRACKER_H_
#define SERVICE_TRACKER_H_

#include "headers.h"

struct fwServiceTracker {
	SERVICE_TRACKER tracker;
	SERVICE_TRACKER_CUSTOMIZER customizer;
	SERVICE_LISTENER listener;
	ARRAY_LIST tracked;
};

typedef struct fwServiceTracker * FW_SERVICE_TRACKER;

struct tracked {
	SERVICE_REFERENCE reference;
	void * service;
};

typedef struct tracked * TRACKED;

SERVICE_TRACKER tracker_create(BUNDLE_CONTEXT context, char * className, SERVICE_TRACKER_CUSTOMIZER customizer);

void tracker_open(SERVICE_TRACKER tracker);
void tracker_close(SERVICE_TRACKER tracker);
void tracker_destroy(SERVICE_TRACKER tracker);

SERVICE_REFERENCE tracker_getServiceReference(SERVICE_TRACKER tracker);
ARRAY_LIST tracker_getServiceReferences(SERVICE_TRACKER tracker);

void * tracker_getService(SERVICE_TRACKER tracker);
ARRAY_LIST tracker_getServices(SERVICE_TRACKER tracker);
void * tracker_getServiceByReference(SERVICE_TRACKER tracker, SERVICE_REFERENCE reference);

void tracker_serviceChanged(SERVICE_LISTENER listener, SERVICE_EVENT event);

FW_SERVICE_TRACKER findFwServiceTracker(SERVICE_TRACKER tracker);

#endif /* SERVICE_TRACKER_H_ */