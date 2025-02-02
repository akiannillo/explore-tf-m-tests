/*
 * Copyright (c) 2017-2020, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_integ_test.h"

#ifdef TEST_FRAMEWORK_NS
#include "test/framework/test_framework_integ_test.h"
#endif

#ifdef TEST_FRAMEWORK_S
#include \
  "test/test_services/tfm_secure_client_service/tfm_secure_client_service_api.h"
#endif

#if defined(TEST_FRAMEWORK_NS) || defined(TEST_FRAMEWORK_S)
/**
 * \brief Services test thread
 *
 */
__attribute__((noreturn))
void test_app(void *argument)
{
    UNUSED_VARIABLE(argument);

#ifdef TEST_FRAMEWORK_S
    /* FIXME: The non-secure audit log test currently relies on the fact that
     * the audit log secure test is run first. However the Non-secure tests
     * represent simpler and more common test cases which would make more sense
     * to be run first. Therefore if this dependency is removed the execution
     * order of these test classes should be reversed. */
    tfm_secure_client_run_tests();
#endif
#ifdef TEST_FRAMEWORK_NS
    tfm_non_secure_client_run_tests();
#endif
    /* End of test */
    for (;;) {
    }
}
#endif /* TEST_FRAMEWORK_NS OR TEST_FRAMEWORK_S */
