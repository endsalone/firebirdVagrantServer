/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2004 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Ard Biesheuvel <abies@php.net>                               |
  +----------------------------------------------------------------------+
*/

/* $Id: pdo_firebird.c,v 1.3 2005/02/09 05:00:58 wez Exp $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "pdo/php_pdo.h"
#include "pdo/php_pdo_driver.h"
#include "php_pdo_firebird.h"
#include "php_pdo_firebird_int.h"

function_entry pdo_firebird_functions[] = { /* {{{ */
	{NULL, NULL, NULL}
};
/* }}} */

zend_module_entry pdo_firebird_module_entry = { /* {{{ */
	STANDARD_MODULE_HEADER,
	"PDO_Firebird",
	pdo_firebird_functions,
	PHP_MINIT(pdo_firebird),
	PHP_MSHUTDOWN(pdo_firebird),
	NULL,
	NULL,
	PHP_MINFO(pdo_firebird),
	"0.2",
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PDO_FIREBIRD
ZEND_GET_MODULE(pdo_firebird)
#endif

PHP_MINIT_FUNCTION(pdo_firebird) /* {{{ */
{
	php_pdo_register_driver(&pdo_firebird_driver);

	return SUCCESS;
}
/* }}} */

PHP_MSHUTDOWN_FUNCTION(pdo_firebird) /* {{{ */
{
	php_pdo_unregister_driver(&pdo_firebird_driver);

	return SUCCESS;
}
/* }}} */

PHP_MINFO_FUNCTION(pdo_firebird) /* {{{ */
{
	php_info_print_table_start();
	php_info_print_table_header(2, "PDO Driver for Firebird/InterBase", "enabled");
	php_info_print_table_end();
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
