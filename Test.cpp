
#include "mat.hpp"
#include "doctest.h"
using namespace ariel;
using namespace std;


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

	CHECK(nospaces(mat(5, 3, '!', '-')) == nospaces("!!!!!\n"
													"!---!\n"
													"!!!!!"));

    CHECK(nospaces(mat(5, 7, '$', '-')) == nospaces("$$$$$\n"
													"$---$\n"
                                                    "$-$-$\n"
                                                    "$-$-$\n"
                                                    "$-$-$\n"
                                                    "$---$\n"
													"$$$$$"));

    CHECK(nospaces(mat(1, 3, '$', '-')) == nospaces("$\n"
                                                    "$\n"
                                                    "$"));

    CHECK(nospaces(mat(5, 5, '5', '-')) == nospaces("55555\n"
													"5---5\n"
													"5-5-5\n"
                                                    "5---5\n"
                                                    "55555"));

      CHECK(nospaces(mat(5, 7, '+', '-')) == nospaces("+++++\n"
													  "+---+\n"
													  "+-+-+\n"
                                                      "+-+-+\n"
                                                      "+-+-+\n"
                                                      "+---+\n"
                                                      "+++++"));

    CHECK(nospaces(mat(1,1, '$', '-')) == nospaces("$"));         

    CHECK(nospaces(mat(11, 7, '@', '-')) == nospaces("@@@@@@@@@@@\n"
													 "@---------@\n"
													 "@-@@@@@@@-@\n"
													 "@-@-----@-@\n"
													 "@-@@@@@@@-@\n"
													 "@---------@\n"
													 "@@@@@@@@@@@"));

    CHECK(nospaces(mat(13, 7, '*', '-')) == nospaces("*************\n"
													 "*-----------*\n"
													 "*-*********-*\n"
													 "*-*-------*-*\n"
													 "*-*********-*\n"
													 "*-----------*\n"
													 "*************"));

    CHECK(nospaces(mat(11, 9, '@', '-')) == nospaces("@@@@@@@@@@@\n"
													 "@---------@\n"
													 "@-@@@@@@@-@\n"
													 "@-@-----@-@\n"
                                                     "@-@-@@@-@-@\n"
                                                     "@-@-----@-@\n"
													 "@-@@@@@@@-@\n"
													 "@---------@\n"
													 "@@@@@@@@@@@"));

    CHECK(nospaces(mat(13, 9, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													 "@-----------@\n"
													 "@-@@@@@@@@@-@\n"
													 "@-@-------@-@\n"
                                                     "@-@-@@@@@-@-@\n"
                                                     "@-@-------@-@\n"
													 "@-@@@@@@@@@-@\n"
													 "@-----------@\n"
													 "@@@@@@@@@@@@@"));

	CHECK(nospaces(mat(13, 13, '#', '#')) == nospaces("#############\n"
													  "#############\n"
													  "#############\n"
													  "#############\n"
                                                      "#############\n"
                                                      "#############\n"
													  "#############\n"
													  "#############\n"
													  "#############\n"
													  "#############\n"
													  "#############\n"
													  "#############\n"
													  "#############"));

	CHECK(nospaces(mat(13, 15, '&', '-')) == nospaces("&&&&&&&&&&&&&\n"
													 "&-----------&\n"
													 "&-&&&&&&&&&-&\n"
													 "&-&-------&-&\n"
                                                     "&-&-&&&&&-&-&\n"
													 "&-&-&---&-&-&\n"
													 "&-&-&-&-&-&-&\n"
													 "&-&-&-&-&-&-&\n"
													 "&-&-&-&-&-&-&\n"
													 "&-&-&---&-&-&\n"
													 "&-&-&&&&&-&-&\n"
                                                     "&-&-------&-&\n"
													 "&-&&&&&&&&&-&\n"
													 "&-----------&\n"
													 "&&&&&&&&&&&&&"));
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(0, 0, '$', '%'));
	CHECK_THROWS(mat(2, 5, '$', '%'));
	CHECK_THROWS(mat(0, 5, '$', '%'));
	CHECK_THROWS(mat(-1, 6, '$', '%'));
	CHECK_THROWS(mat(0, -2, '$', '%'));
    CHECK_THROWS(mat(1, 0, '$', '%'));
    CHECK_THROWS(mat(0, 1, '$', '%'));
    CHECK_THROWS(mat(2, 2, '$', '%'));
    CHECK_THROWS(mat(12, 13, '$', '%'));
    CHECK_THROWS(mat(-1, -1, '$', '%'));
    CHECK_THROWS(mat(1, 7, '$', 5));
    CHECK_THROWS(mat(3, 5, 4, '%'));
    CHECK_THROWS(mat(-1, -1, 11, 1));
    CHECK_THROWS(mat(1, 1, 1, 1));
}