#pragma once

struct Ranking
{
    int point;
    Ranking *next;
} typedef Ranking;
struct User
{
    int user_id;
    char *fullname;
    int age;
} typedef User;

int conn(char *url); // connection to database with an url

int get_user_ranking(int user_id);
User get_user_info(int user_id);