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
 * dm_dependency_manager.h
 *
 *  \date       22 Feb 2014
 *  \author     <a href="mailto:dev@celix.apache.org">Apache Celix Project Team</a>
 *  \copyright  Apache License, Version 2.0
 */

#ifndef DM_DEPENDENCY_MANAGER_H_
#define DM_DEPENDENCY_MANAGER_H_


#include "bundle_context.h"
#include "celix_errno.h"
#include "array_list.h"
#include "dm_info.h"
#include "dm_component.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dm_dependency_manager *dm_dependency_manager_pt;

/**
 * Creates a dependency manager.
 * Caller has ownership.
 */
celix_status_t dependencyManager_create(bundle_context_pt context, dm_dependency_manager_pt *manager);

/**
 * Destroys the provided dependency manager
 */
void dependencyManager_destroy(dm_dependency_manager_pt manager);

/**
 * Adds a DM component to the dependency manager
 */
celix_status_t dependencyManager_add(dm_dependency_manager_pt manager, dm_component_pt component);

/**
 * Removes all DM components from the dependency manager
 */
celix_status_t dependencyManager_removeAllComponents(dm_dependency_manager_pt manager);

/**
 * Create and returns a DM Info struct. Which contains information about the state of the DM components
 * Caller has ownership.
 */
celix_status_t dependencyManager_getInfo(dm_dependency_manager_pt manager, dm_dependency_manager_info_pt *info);

/**
 * Destroys a DM info struct.
 */
void dependencyManager_destroyInfo(dm_dependency_manager_pt manager, dm_dependency_manager_info_pt info);

#ifdef __cplusplus
}
#endif

#endif /* DM_DEPENDENCY_MANAGER_H_ */
