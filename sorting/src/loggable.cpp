#include "loggable.h"
#include <stdio.h>
#include <stdarg.h>

Loggable::Loggable( log_level_e log_level ) : m_log_level(log_level)
{
	/* Nothing to do */
}

Loggable::~Loggable()
{
	/* Nothing to do */
}

/** @brief Update minimum log level for this object
 *
 * @param[in] log_level log_level_e value to use as the minimum
 */
void Loggable::set_log_level( log_level_e log_level )
{
	m_log_level = log_level;
}

/** @brief Log at the ERROR level
 *
 * @param[in] fmt C-string explaining the format in printf
 * @param[in] ... Variable list of args to pass into printf
 */
void Loggable::error_log( const char* fmt, ... )
{
	if (LOG_LEVEL_ERROR <= m_log_level)
	{
		va_list args;
		va_start( args, fmt );
		vprintf( fmt, args );
		va_end(args);
	}
	else { /* Log level too low, do nothing */ }
}

/** @brief Log at the INFO level
 *
 * @param[in] fmt C-string explaining the format in printf
 * @param[in] ... Variable list of args to pass into printf
 */
void Loggable::info_log( const char* fmt, ... )
{
	if (LOG_LEVEL_INFO <= m_log_level)
	{
		va_list args;
		va_start( args, fmt );
		vprintf( fmt, args );
		va_end(args);
	}
	else { /* Log level too low, do nothing */ }
}

/** @brief Log at the DEBUG level
 *
 * @param[in] fmt C-string explaining the format in printf
 * @param[in] ... Variable list of args to pass into printf
 */
void Loggable::debug_log( const char* fmt, ... )
{
	if (LOG_LEVEL_DEBUG <= m_log_level)
	{
		va_list args;
		va_start( args, fmt );
		vprintf( fmt, args );
		va_end(args);
	}
	else { /* Log level too low, do nothing */ }
}
