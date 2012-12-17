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
 * connection_listener.h
 *
 *  \date       Nov 4, 2012
 *  \author    	<a href="mailto:celix-dev@incubator.apache.org">Apache Celix Project Team</a>
 *  \copyright	Apache License, Version 2.0
 */

#ifndef connectionListener_H_
#define connectionListener_H_

#include <apr_pools.h>

#include <bundle_context.h>
#include <celix_errno.h>

#include "remote_shell.h"

typedef struct connection_listener *connection_listener_t;

celix_status_t connectionListener_create(apr_pool_t *pool, remote_shell_t remoteShell, apr_int64_t port, connection_listener_t *instance);

celix_status_t connectionListener_start(connection_listener_t instance);
celix_status_t connectionListener_stop(connection_listener_t instance);

#endif /* connectionListener_H_ */