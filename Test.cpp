/**
 * unit test to phonetic search
 * AUTHOR: RoiPeleg
 * */
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of v and w")
{
    string text = "vvv void werwolves";
    CHECK(find(text, "void") == string("void"));
    CHECK(find(text, "woid") == string("void"));
    CHECK(find(text, "werwolves") == string("werwolves"));
    CHECK(find(text, "verwolves") == string("werwolves"));
    CHECK(find(text, "wervolves") == string("werwolves"));
    CHECK(find(text, "vervolves") == string("werwolves"));
    CHECK(find(text, "werwolwes") == string("werwolves"));
    CHECK(find(text, "verwolwes") == string("werwolves"));
    CHECK(find(text, "vervolwes") == string("werwolves"));
}
TEST_CASE("Test replacement of b, f and p")
{
    string text = "bad fun ggg pie beef bitmap";
    CHECK(find(text, "bad") == string("bad"));
    CHECK(find(text, "fad") == string("bad"));
    CHECK(find(text, "pad") == string("bad"));
    CHECK(find(text, "beef") == string("beef"));
    CHECK(find(text, "beeb") == string("beef"));
    CHECK(find(text, "beep") == string("beef"));
    CHECK(find(text, "bitmap") == string("bitmap"));
    CHECK(find(text, "fitmap") == string("bitmap"));
    CHECK(find(text, "pitmap") == string("bitmap"));
    CHECK(find(text, "bitmaf") == string("bitmap"));
    CHECK(find(text, "bitmab") == string("bitmap"));
}

TEST_CASE("Test replacement of g and j")
{
    string text = "good job joy straightjacket";
    CHECK(find(text, "good") == string("good"));
    CHECK(find(text, "jood") == string("good"));
    CHECK(find(text, "joy") == string("joy"));
    CHECK(find(text, "goy") == string("joy"));
    CHECK(find(text, "gob") == string("job"));
    CHECK(find(text, "straightjacket") == string("straightjacket"));
    CHECK(find(text, "straightgacket") == string("straightjacket"));
    CHECK(find(text, "straijhtgacket") == string("straightjacket"));
    CHECK(find(text, "straijhtjacket") == string("straightjacket"));
    CHECK(find(text, "straightgacket") == string("straightjacket"));
}

TEST_CASE("Test replacement of c , k and q")
{
    string text = "kill cill ql sql clock";
    CHECK(find(text, "kill") == string("kill"));
    CHECK(find(text, "cill") == string("kill"));
    CHECK(find(text, "qill") == string("kill"));
    CHECK(find(text, "sql") == string("sql"));
    CHECK(find(text, "skl") == string("sql"));
    CHECK(find(text, "scl") == string("sql"));
    CHECK(find(text, "scl") == string("sql"));
    CHECK(find(text, "zql") == string("sql"));
    CHECK(find(text, "clocq") == string("clock"));
    CHECK(find(text, "clokk") == string("clock"));
    CHECK(find(text, "qlock") == string("clock"));
    CHECK(find(text, "qloqk") == string("clock"));
}

TEST_CASE("Test replacement of s and z")
{
    string text = "zzzz sleep zzz system quizzes";
    CHECK(find(text, "sleep") == string("sleep"));
    CHECK(find(text, "zleep") == string("sleep"));
    CHECK(find(text, "system") == string("system"));
    CHECK(find(text, "syztem") == string("system"));
    CHECK(find(text, "quizzes") == string("quizzes"));
    CHECK(find(text, "quisses") == string("quizzes"));
    CHECK(find(text, "quiszes") == string("quizzes"));
    CHECK(find(text, "quizses") == string("quizzes"));
    CHECK(find(text, "quiszez") == string("quizzes"));
    CHECK(find(text, "quizzez") == string("quizzes"));
    CHECK(find(text, "quissez") == string("quizzes"));
}

TEST_CASE("Test replacement of d and t")
{
    string text = "dude tt tree bullet gotta get out";
     CHECK(find(text, "dd") == string("tt"));
    CHECK(find(text, "dude") == string("dude"));
    CHECK(find(text, "tute") == string("dude"));
    CHECK(find(text, "dute") == string("dude"));
    CHECK(find(text, "tree") == string("tree"));
    CHECK(find(text, "dree") == string("tree"));
    CHECK(find(text, "bullet") == string("bullet"));
    CHECK(find(text, "bulled") == string("bullet"));
    CHECK(find(text, "out") == string("out"));
    CHECK(find(text, "oud") == string("out"));
    CHECK(find(text, "gotta") == string("gotta"));
    CHECK(find(text, "godda") == string("gotta"));
    CHECK(find(text, "godta") == string("gotta"));
    CHECK(find(text, "gotda") == string("gotta"));
}

TEST_CASE("Test replacement of o and u")
{
    string text = "oak out ooa quadruplication";
    CHECK(find(text, "oak") == string("oak"));
    CHECK(find(text, "uak") == string("oak"));
    CHECK(find(text, "out") == string("out"));
    CHECK(find(text, "uut") == string("out"));
    CHECK(find(text, "oot") == string("out"));
    CHECK(find(text, "quadruplication") == string("quadruplication"));
    CHECK(find(text, "qoadruplication") == string("quadruplication"));
    CHECK(find(text, "quadroplication") == string("quadruplication"));
    CHECK(find(text, "quadruplicatiun") == string("quadruplication"));
    CHECK(find(text, "quadroplicatiun") == string("quadruplication"));
    CHECK(find(text, "qoadroplicatiun") == string("quadruplication"));
}

TEST_CASE("Test replacement of i and y")
{
    string text = "island you young imp yoyo";
    CHECK(find(text, "island") == string("island"));
    CHECK(find(text, "ysland") == string("island"));
    CHECK(find(text, "you") == string("you"));
    CHECK(find(text, "iou") == string("you"));
    CHECK(find(text, "imp") == string("imp"));
    CHECK(find(text, "ymp") == string("imp"));
    CHECK(find(text, "young") == string("young"));
    CHECK(find(text, "ioung") == string("young"));
    CHECK(find(text, "yoyo") == string("yoyo"));
    CHECK(find(text, "ioyo") == string("yoyo"));
    CHECK(find(text, "yoio") == string("yoyo"));
}

TEST_CASE("Test replacement of lowercase letters and uppercase letters")
{
    string text = "Bob is a lawyer";
    CHECK(find(text, "Bob") == string("Bob"));
    CHECK(find(text, "BoB") == string("Bob"));
    CHECK(find(text, "bob") == string("Bob"));
    CHECK(find(text, "boB") == string("Bob"));
    CHECK(find(text, "laWyer") == string("lawyer"));
    CHECK(find(text, "laWYer") == string("lawyer"));
    CHECK(find(text, "LAWYER") == string("lawyer"));
    CHECK(find(text, "lawyER") == string("lawyer"));
    CHECK(find(text, "LAWYEr") == string("lawyer"));
    CHECK(find(text, "IS") == string("is"));
    CHECK(find(text, "Is") == string("is"));
    CHECK(find(text, "iS") == string("is"));
}
