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
 * activator.c
 *
 *  \date       Aug 23, 2010
 *  \author    	<a href="mailto:celix-dev@incubator.apache.org">Apache Celix Project Team</a>
 *  \copyright	Apache License, Version 2.0
 */
#include <stdlib.h>

#include "bundle_activator.h"
#include "bundle_context.h"
#include "publisher_private.h"
#include "service_registration.h"

struct activatorData {
	PUBLISHER_SERVICE ps;
	PUBLISHER pub;

	SERVICE_REGISTRATION reg;
};

celix_status_t bundleActivator_create(bundle_context_t context, void **userData) {
    apr_pool_t *pool;
    celix_status_t status = bundleContext_getMemoryPool(context, &pool);
    if (status == CELIX_SUCCESS) {
        *userData = apr_palloc(pool, sizeof(struct activatorData));
    } else {
        status = CELIX_START_ERROR;
    }
    return CELIX_SUCCESS;
}

celix_status_t bundleActivator_start(void * userData, bundle_context_t context) {
    celix_status_t status = CELIX_SUCCESS;
    apr_pool_t *pool;
    status = bundleContext_getMemoryPool(context, &pool);
    if (status == CELIX_SUCCESS) {
		PROPERTIES props = properties_create();

        struct activatorData * data = (struct activatorData *) userData;
        data->ps = apr_pcalloc(pool, sizeof(*(data->ps)));
        data->pub = apr_pcalloc(pool, sizeof(*(data->pub)));
        data->ps->invoke = publisher_invoke;
        data->ps->publisher = data->pub;
        data->reg = NULL;
        
		properties_set(props, "id", "B");

    	bundleContext_registerService(context, PUBLISHER_NAME, data->ps, props, &data->reg);
    } else {
        status = CELIX_START_ERROR;
    }
    return status;
}

celix_status_t bundleActivator_stop(void * userData, bundle_context_t context) {
    celix_status_t status = CELIX_SUCCESS;

    struct activatorData * data = (struct activatorData *) userData;
	serviceRegistration_unregister(data->reg);

    return status;
}

celix_status_t bundleActivator_destroy(void * userData, bundle_context_t context) {
    return CELIX_SUCCESS;
}