
#include <stdio.h>

#define MAX_SONGS 100

struct Song {
    char title[50];
    char artist[50];
    int year;
};

struct Song songs[MAX_SONGS];

int numSongs = 0;

int addSong(char* title, char* artist, int year) {
    if (numSongs < MAX_SONGS) {
        struct Song newSong;
        strcpy(newSong.title, title);
        strcpy(newSong.artist, artist);
        newSong.year = year;
        
        songs[numSongs++] = newSong;
        
        return 1; // Song added successfully
    } else {
        return 0; // Unable to add song, array full
    }
}

void displaySongs() {
    for (int i = 0; i < numSongs; i++) {
        printf("%s by %s (%d)\n", songs[i].title, songs[i].artist, songs[i].year);
    }
}

int main() {
    addSong("Bohemian Rhapsody", "Queen", 1975);
    addSong("Smells Like Teen Spirit", "Nirvana", 1991);
    addSong("Shape of You", "Ed Sheeran", 2017);
    
    displaySongs();
    
    return 0;
}
