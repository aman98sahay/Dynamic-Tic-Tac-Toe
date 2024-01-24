#pragma once 
#include <cstdint>


enum class gameBlock : int8_t {
	UNSET,
	SET_WITH_O,
	SET_WITH_X,
	SET_WITH_O_WITH_WINNING_SEQUENCE,
	SET_WITH_X_WITH_WINNING_SEQUENCE
};