#include "../src/type/type.h"
#include "lest.hpp"

using namespace ithare::util::type;

#ifdef WARNINGS_EXPECTED
static_assert(-1>1U);
static_assert( short(-1) < (unsigned short)(1) );//stands (if sizeof(short)<sizeof(int))!
static_assert( int64_t(-1) < 1U );
static_assert( -1 > uint64_t(1) );
static_assert( -1 == unsigned(-1) );
#endif

static_assert( intuitive::lt(-1,1U) );
static_assert( intuitive::lt(short(-1),(unsigned short)(1)) );
static_assert( intuitive::lt(int64_t(-1), 1U) );
static_assert( intuitive::lt(-1,uint64_t(1)) );
static_assert( intuitive::le(-1,1U) );

static_assert( intuitive::gt(1U,-1) );
static_assert( intuitive::gt((unsigned short)(1),short(-1)) );
static_assert( intuitive::gt( 1U,int64_t(-1)) );
static_assert( intuitive::gt(uint64_t(1),-1) );
static_assert( intuitive::ge(1U,-1) );

static_assert( !intuitive::eq(-1,unsigned(-1)) );
static_assert( intuitive::ne(-1,unsigned(-1)) );

const lest::test specification[] = {
	CASE("built-in") {
		EXPECT(-1<1);
#ifdef WARNINGS_EXPECTED
		EXPECT(-1>1U);
		EXPECT( short(-1) < (unsigned short)(1) );//stands (if sizeof(short)<sizeof(int))!
		EXPECT( int64_t(-1) < 1U );
		EXPECT( -1 > uint64_t(1) );
		EXPECT( -1 == unsigned(-1) );
#endif
	},
	CASE("lt") {
		EXPECT( intuitive::lt(-1,1U) );
		EXPECT( intuitive::lt(short(-1),(unsigned short)(1)) );
		EXPECT( intuitive::lt(int64_t(-1), 1U) );
		EXPECT( intuitive::lt(-1,uint64_t(1)) );
		EXPECT( intuitive::le(-1,1U) );
	},
	CASE("gt") {
		EXPECT( intuitive::gt(1U,-1) );
		EXPECT( intuitive::gt((unsigned short)(1),short(-1)) );
		EXPECT( intuitive::gt( 1U,int64_t(-1)) );
		EXPECT( intuitive::gt(uint64_t(1),-1) );
		EXPECT( intuitive::ge(1U,-1) );
	},
	CASE("eq") {
		EXPECT( !intuitive::eq(-1,unsigned(-1)) );
		EXPECT( intuitive::ne(-1,unsigned(-1)) );
	},
};

#define OUT_SIZEOF(t) "sizeof(" #t ")=" << sizeof(t)
#define OUT_CMP(cond) #cond ": " << ((cond)?"true":"false")

int main(int argc, char** argv) {
	std::cout << OUT_SIZEOF(short) << " " << OUT_SIZEOF(int) << " " << OUT_SIZEOF(int64_t) << std::endl;

	std::cout << OUT_CMP( int(-1) < unsigned(1) ) << std::endl;
	std::cout << OUT_CMP( -1 < 1U ) << std::endl;
	std::cout << OUT_CMP( short(-1) < (unsigned short)(1) ) << std::endl;
	std::cout << OUT_CMP( int64_t(-1) < unsigned(1) ) << std::endl;
	std::cout << OUT_CMP( int(-1) < uint64_t(1) ) << std::endl;

	std::cout << OUT_CMP( intuitive::lt(int(-1),unsigned(1)) ) << std::endl;
	std::cout << OUT_CMP( intuitive::lt(-1,1U) ) << std::endl;
	std::cout << OUT_CMP( intuitive::lt(short(-1), (unsigned short)(1)) ) << std::endl;
	std::cout << OUT_CMP( intuitive::lt(int64_t(-1), unsigned(1)) ) << std::endl;
	std::cout << OUT_CMP( intuitive::lt(int(-1), uint64_t(1)) ) << std::endl;

	std::cout << OUT_CMP( intuitive::gt(unsigned(1),int(-1)) ) << std::endl;
	std::cout << OUT_CMP( intuitive::gt(1U,-1) ) << std::endl;
	std::cout << OUT_CMP( intuitive::gt((unsigned short)(1),short(-1)) ) << std::endl;
	std::cout << OUT_CMP( intuitive::gt(unsigned(1),int64_t(-1)) ) << std::endl;
	std::cout << OUT_CMP( intuitive::gt(uint64_t(1),int(-1)) ) << std::endl;

	return lest::run(specification,argc,argv);
}

