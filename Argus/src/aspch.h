#pragma once

#include "Argus/Core/PlatformDetection.h"

#ifdef AS_PLATFORM_WINDOWS
#ifndef NOMINMAX
// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
#define NOMINMAX
#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Argus/Core/Base.h"

#include "Argus/Core/Log.h"

#include "Argus/Debug/Instrumentor.h"

#ifdef AS_PLATFORM_WINDOWS
#include <Windows.h>
#endif