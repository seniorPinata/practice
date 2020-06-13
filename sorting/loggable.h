#ifndef LOGGABLE_H
#define LOGGABLE_H

/** @brief Types of log levels */
enum log_level_e
{
	LOG_LEVEL_ERROR = 0,
	LOG_LEVEL_INFO,
	LOG_LEVEL_DEBUG
};

class Loggable
{
private:
	log_level_e m_log_level;
public:
	Loggable( log_level_e log_level );
	~Loggable();
	void error_log( const char* fmt, ... );
	void info_log( const char* fmt, ... );
	void debug_log( const char* fmt, ... );
	void set_log_level( log_level_e log_level );
};

#endif /* LOGGABLE_H */