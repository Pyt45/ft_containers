#include "Data.Class.hpp"

DataClass::DataClass( void ) {
	_vF = new std::vector<uint64_t>(static_cast<uint64_t>(std::numeric_limits<int>::max()));
}