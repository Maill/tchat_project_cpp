#pragma once

#define HAVE_STRUCT_TIMESPEC

#include <iostream>
#include <string>
#include <pthread.h>

#ifndef __WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#include "Global.h"

using namespace std;

class Thread {
public:
	pthread_t threadId{};

private:
	static pthread_mutex_t mutex;

public:
	Thread();
	int create(void *Callback, void *args);
	int join() const;

	static int init_mutex();
	static int lock_mutex(const string& identifier);
	static int unlock_mutex(const string& identifier);
};