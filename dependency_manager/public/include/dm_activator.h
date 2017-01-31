/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0 
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *  KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * dm_activator_base.h
 *
 *  \date       26 Jul 2014
 *  \author     <a href="mailto:dev@celix.apache.org">Apache Celix Project Team</a>
 *  \copyright  Apache License, Version 2.0
 */


#ifndef DM_ACTIVATOR_BASE_H_
#define DM_ACTIVATOR_BASE_H_


#include "bundle_context.h"
#include "celix_errno.h"
#include "dm_dependency_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Should be implemented by a bundle specific DM activator.
 * Should allocate and initialize a bundle specific activator struct.
 */
celix_status_t dm_create(bundle_context_pt context, void ** userData);

/**
 * Should be implemented by a bundle specific DM activator.
 * Will be called after the dm_create function.
 * Can be used to specify with use of the provided dependency manager the bundle specific components.
 */
celix_status_t dm_init(void * userData, bundle_context_pt context, dm_dependency_manager_pt manager);

/**
 * Should be implemented by a bundle specific DM activator.
 * Should deinitialize and deallocate the undle specific activator struct.
 */
celix_status_t dm_destroy(void * userData, bundle_context_pt context, dm_dependency_manager_pt manager);

#ifdef __cplusplus
}
#endif

#endif /* DM_ACTIVATOR_BASE_H_ */
