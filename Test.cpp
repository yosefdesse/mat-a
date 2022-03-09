/**
 * AUTHORS: <Yosef Desse>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));


    CHECK(nospaces(mat(7, 5, '@', '-')) == nospaces( "@@@@@@@\n"
													 "@-----@\n"
													 "@-@@@-@\n"
													 "@-----@\n"
													 "@@@@@@@"));

	CHECK(nospaces(mat(7, 7, '@', '-')) == nospaces( "@@@@@@@\n"
													 "@-----@\n"
													 "@-@@@-@\n"
													 "@-@-@-@\n"
													 "@-@@@-@\n"
													 "@-----@\n"
													 "@@@@@@@"));


	CHECK(nospaces(mat(3, 5, '@', '-')) == nospaces( "@@@\n"
													 "@-@\n"
													 "@-@\n"
													 "@-@\n"
													 "@@@"));	


	CHECK(nospaces(mat(5, 7, '@', '-')) == nospaces( "@@@@@\n"
													 "@---@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@---@\n"
													 "@@@@@"));


	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                     "@-----------@\n"
                                                     "@-@@@@@@@@@-@\n"
                                                     "@-----------@\n"
                                                     "@@@@@@@@@@@@@)\n"));							


	CHECK(nospaces(mat(5, 13, '@', '-')) == nospaces("@@@@@\n"
													 "@---@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@---@\n"
													 "@@@@@"));										 												 


	CHECK(nospaces(mat(11, 15, '@', '-')) == nospaces("@@@@@@@@@@@\n"
                                                      "@---------@\n"
                                                      "@-@@@@@@@-@\n"
                                                      "@-@-----@-@\n"
                                                      "@-@-@@@-@-@\n"
                                                      "@-@-@-@-@-@\n"
                                                      "@-@-@-@-@-@\n"
                                                      "@-@-@-@-@-@\n"
                                                      "@-@-@-@-@-@\n"
                                                      "@-@-@-@-@-@\n"
                                                      "@-@-@@@-@-@\n"
                                                      "@-@-----@-@\n"
                                                      "@-@@@@@@@-@\n"
                                                      "@---------@\n"
                                                      "@@@@@@@@@@@\n"));												 

}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(9, 6, '$', '%'));
    CHECK_THROWS(mat(2, 5, '$', '%'));
    CHECK_THROWS(mat(20, 5, '$', '%'));
	for(int i=1 ; i<20 ; i++){
		int j =i+1;
		CHECK_THROWS(mat(i,j,'@','-'));
	}
	int negative_num=-20;
	for (int i = 0; i > negative_num ; i--) {
		for (int j = 0; j <20 ; j++) {
          CHECK_THROWS(mat(i, j, '$', '%'));
		}
    }
}


