// Name: Noah Poulatian
// Date: 4/22/26
// Assignment: Assignment 7 - Music Playlist
#include "Playlist.h"
#include <list>

void AddSong(list<Song>& playlist) {
    Song newSong;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // cin.ignore but better
    
    cout<<"Enter song title: ";
    getline(cin,newSong.title);
    cout<<"Enter artist: ";
    getline(cin,newSong.artist);

    playlist.push_back(newSong);

    cout<<"Added "<<newSong.title<<" by "<<newSong.artist<<endl;
    return;
}

void RemoveSong(list<Song>& playlist) {
    int songIndex;
    DisplayPlaylist(playlist);
    cout<<"Enter the number of the song to remove: ";
    cin>>songIndex;
    songIndex-=1;
    if (songIndex < 0 || songIndex >= playlist.size()) {
        cout<<"Invalid selection."<<endl;
        return;
    }
    auto it = playlist.begin();
    for (int i = 0; i < playlist.size(); i++) {
        if(songIndex == i) {
            cout<<"Removed: "<<(*it).title<<" by "<<(*it).artist<<endl;
            playlist.erase(it);
            break;
        }
        ++it;
    }
    
}

void DisplayPlaylist(const list<Song>& playlist) {
    if(playlist.size() < 1) {
        cout<<"Playlist is empty."<<endl;
        return;
    }
    auto it = playlist.begin();

    cout<<"===== PLAYLIST ====="<<endl;
    for(int i = 0; i < playlist.size(); i++){
        cout<<i+1<<". "<<(*it).title<<" by "<<(*it).artist<<endl;
        ++it;
    }
    cout<<"===================="<<endl;
    cout<<"Total songs: "<<playlist.size()<<endl;
    return;
}

void MoveSong(list<Song>& playlist) {
    int songIndex;
    int newSongPosition;
    if(playlist.size() < 2) {
        cout<<"Not enough songs to move."<<endl;
        return;
    }
    DisplayPlaylist(playlist);
    cout<<"Enter the number of the song to move: ";
    cin>>songIndex;
    if(songIndex > playlist.size() || songIndex < 0) {
        cout<<"Invalid selection."<<endl;
        return;
    }
    cout<<"Move to position (1-[size]): ";
    cin>>newSongPosition;
    if(newSongPosition > playlist.size() || newSongPosition < 0) {
        cout<<"Invalid selection."<<endl;
        return;
    }
    auto it = playlist.begin();
    advance(it, songIndex - 1);
    Song newSong = *it;
    playlist.erase(it);

    auto it2 = playlist.begin();
    advance(it2, newSongPosition - 1);
    playlist.insert(it2, newSong);

    cout<<"Moved: "<<newSong.title<<" by "<<newSong.artist<<" to position "<<newSongPosition<<endl;
    return;
}

void ShufflePlaylist(list<Song>& playlist) {
    if(playlist.size() < 2) {
        cout<<"Not enough songs to shuffle."<<endl;
    }
    else {
        playlist.reverse();
        cout<<"Playlist has been reversed!"<<endl;
    }
    return;
}

int main(){
    int choice;
    list<Song> playlist;
    do
    {
        cout<<"===== MUSIC PLAYLIST ====="<<endl;
        cout<<"1. Add a song"<<endl;
        cout<<"2. Remove a song"<<endl;
        cout<<"3. Display playlist"<<endl;
        cout<<"4. Move a song"<<endl;
        cout<<"5. Shuffle (reverse) playlist"<<endl;
        cout<<"6. Quit"<<endl;
        cout<<"=========================="<<endl;
        cout<<"Enter your choice: ";

        cin>>choice;

        switch (choice)
        {
        case 1:
            AddSong(playlist);
            break;
        
        case 2:
            RemoveSong(playlist);
            break;

        case 3:
            DisplayPlaylist(playlist);
            break;

        case 4:
            MoveSong(playlist);
            break;

        case 5:
            ShufflePlaylist(playlist);
            break;

        case 6:
            break;

        default:
            cout<<"Invalid choice. Please try again."<<endl;
        }

    } while (choice != 6);
    
    cout<<"Goodbye!";
    return 0;
}