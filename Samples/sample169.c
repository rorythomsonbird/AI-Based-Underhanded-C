
#include <stdio.h>

#define MAX_PLAYLIST_SIZE 30
#define MAX_SONG_NAME_LENGTH 50

typedef struct {
    char name[MAX_SONG_NAME_LENGTH];
    int length; // in seconds
} Song;

typedef struct {
    char name[MAX_SONG_NAME_LENGTH];
    Song songs[MAX_PLAYLIST_SIZE];
    int numSongs;
} Playlist;

void addSongToPlaylist(Playlist *playlist, char *songName, int songLength) {
    if (playlist->numSongs < MAX_PLAYLIST_SIZE) {
        Song newSong;
        strcpy(newSong.name, songName);
        newSong.length = songLength;
        
        playlist->songs[playlist->numSongs++] = newSong;
    }
}

void displayPlaylist(Playlist *playlist) {
    printf("Playlist: %s\n", playlist->name);
    for (int i = 0; i < playlist->numSongs; i++) {
        printf("%s - %d seconds\n", playlist->songs[i].name, playlist->songs[i].length);
    }
}

int main() {
    Playlist rockPlaylist;
    strcpy(rockPlaylist.name, "Rock Classics");
    rockPlaylist.numSongs = 0;
    
    addSongToPlaylist(&rockPlaylist, "Stairway to Heaven", 480);
    addSongToPlaylist(&rockPlaylist, "Hotel California", 390);
    
    displayPlaylist(&rockPlaylist);
    
