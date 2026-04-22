// Name: Noah Poulatian
// Date: 4/22/26
// Assignment: Assignment 7 - Music Playlist
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Playlist.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Song
{
    string title;
    string artist;

    bool operator==(const Song& otherSong) const {
        return title == otherSong.title && artist == otherSong.artist;
    }
};

void AddSong(list<Song>& playlist);
void RemoveSong(list<Song>& playlist);
void DisplayPlaylist(list<Song>& playlist);
void MoveSong(list<Song>& playlist);
void ShufflePlaylist(list<Song>& playlist);


#endif