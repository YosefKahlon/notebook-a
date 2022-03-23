/**
 *
 *
 * AUTHORS: <Yosef Or Kahlon>
 *
 * Date: 2022 - 3
 */

#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"

using namespace ariel;

#include <string>
#include <algorithm>

using namespace std;


//        test.write(1, 1, 1, Direction::Horizontal, "Y");
//        CHECK_THROWS(test.write(1, 1, 1, Direction::Horizontal, "d"));


TEST_CASE (" -- Negative input -- ") {

    Notebook test;
//////////////////////////////////////////////////////////////////////
            SUBCASE("-------------write------------") {
        //negative page
        CHECK_THROWS(test.write(-1, 1, 3, Direction::Horizontal, "d"));
        CHECK_THROWS(test.write(-1, 1, 3, Direction::Vertical, "d"));


        //negative row
        CHECK_THROWS(test.write(1, -1, 3, Direction::Horizontal, "d"));
        CHECK_THROWS(test.write(1, -1, 3, Direction::Vertical, "d"));


        //negative col
        CHECK_THROWS(test.write(1, 1, -3, Direction::Horizontal, "d"));
        CHECK_THROWS(test.write(1, 1, -3, Direction::Vertical, "d"));
    }
//////////////////////////////////////////////////////////////////////
            SUBCASE("-------------read------------") {
        //negative page
        CHECK_THROWS(test.read(-1, 1, 3, Direction::Horizontal, 1));
        CHECK_THROWS(test.read(-1, 1, 3, Direction::Vertical, 1));


        //negative row
        CHECK_THROWS(test.read(1, -1, 3, Direction::Horizontal, 1));
        CHECK_THROWS(test.read(1, -1, 3, Direction::Vertical, 1));


        //negative col
        CHECK_THROWS(test.read(1, 1, -3, Direction::Horizontal, 1));
        CHECK_THROWS(test.read(1, 1, -3, Direction::Vertical, 1));


        //negative length to read
        CHECK_THROWS(test.read(1, 1, 3, Direction::Vertical, -1));
    }
//////////////////////////////////////////////////////////////////////

            SUBCASE("-------------erase------------") {
        //negative page
        CHECK_THROWS(test.erase(-1, 1, 3, Direction::Horizontal, 1));
        CHECK_THROWS(test.erase(-1, 1, 3, Direction::Vertical, 1));

        //negative row
        CHECK_THROWS(test.erase(1, -1, 3, Direction::Horizontal, 1));
        CHECK_THROWS(test.erase(1, -1, 3, Direction::Vertical, 1));


        //negative col
        CHECK_THROWS(test.erase(1, 1, -3, Direction::Horizontal, 1));
        CHECK_THROWS(test.read(1, 1, -3, Direction::Vertical, 1));

        //negative length to read
        CHECK_THROWS(test.erase(1, 1, 3, Direction::Vertical, -2));
    }


}


//////////////////////////////////////////////// TODO
TEST_CASE ("100") {

    string s = "";
    for (int i = 0; i < 102; i++) {
        s += "a";
    }
    Notebook test;

    //should throw exp  about  long string to write
    CHECK_THROWS(test.write(1, 2, 3, Direction::Vertical, s));


    CHECK_THROWS(test.read(2, 2, 4, Direction::Vertical, s.length()));


    CHECK_THROWS(test.read(2, 4, 102, Direction::Vertical, 5));


    CHECK_THROWS(test.erase(2, 4, 102, Direction::Vertical, 5));


}

TEST_CASE ("idk") {
    Notebook test;

    string s = "REPLACE_ME";
    test.write(50, 60, 50, Direction::Vertical, s);
    test.erase(50, 60, 50, Direction::Vertical, s.length());
            CHECK(test.read(50, 60, 50, Direction::Vertical, s.length()) == "~~~~~~~~~~");

    test.write(50, 60, 50, Direction::Vertical, s);
    test.erase(50, 60, 50, Direction::Vertical, s.length() - 1);
            CHECK(test.read(50, 60, 50, Direction::Vertical, s.length()) == "REPLACE_M~");


    test.erase(50, 60, 50, Direction::Vertical, s.length() - 2);
            CHECK_EQ(test.read(50, 60, 50, Direction::Vertical, s.length()), "REPLACE_~~");
    test.write(50, 60, 50 + s.length() - 2, Direction::Vertical, "ME");
            CHECK(test.read(50, 60, 50, Direction::Vertical, s.length()) == "REPLACE_ME");


    test.write(1, 1, 2, Direction::Horizontal, "");
            CHECK(test.read(1, 1, 2, Direction::Horizontal, 1) == "_");

    test.erase(1, 1, 2, Direction::Vertical, 2);
            CHECK(test.read(1, 1, 2, Direction::Vertical, 1) == "~~");


    test.write(2, 10, 10, Direction::Horizontal, "TEST");
            CHECK(test.read(2, 10, 10, Direction::Vertical, 4) == "T___");
            CHECK(test.read(2, 10, 12, Direction::Vertical, 4) == "E___");

    CHECK_FALSE(test.read(2, 10, 10, Direction::Vertical, 4) == " you are right !");
}




