'''
    Design a music juke box using the object oriented principles
    - Jukebox is plays songs or playlist
    - Each song has an Artist
    - For playlist, the first song is played and other songs are added to the queue
    - Relation between playlist and songs is many-to-many
    - Relation between Song and Artist is Many-to-one


- Song:
    - name : string
    - List[Artist]

- Artist:
    - Name

- PlayList:
    - List[Songs]

- JukeBox:
    - songBeingPlayed : string 
'''


from typing import List

class Artist:
    def __init__(self, name):
        self.__name = name

    def get_name(self):
        '''
            Function for getting the artist name
        '''
        return self.__name

class Song:
    def __init__(self, song_name : str, artists : List[Artist]):
        self.__name = song_name
        self.__artist = artists

    def get_song_name(self):
        '''
            function which returns the song names
        '''
        return self.__name

    def get_song_artist_names(self):
        '''
            Function for getting the song artist names
        '''
        artist_names = []
        for artist in self.__artist:
            artist_names.append(artist.get_name())

        return artist_names

    def play_song(self):
        '''
            function which plays the song
        '''
        print(f'Song {self.__name} is being played')

class Playlist:
    def __init__(self, playlist_name : str):
        self.__playlist_name = playlist_name
        self.__playlist_songs : List[Song] = []

    def get_playlist_name(self):
        '''
            Function for getting the name of the playlist
        '''
        return self.__playlist_name
    
    def add_song_to_playlist(self, song : Song):
        '''
            Function for adding the song to the playlist
        '''
        self.__playlist_songs.append(song)

    def get_playlist_songs(self):
        '''
            Function for getting the playlist songs
        '''
        return self.__playlist_songs

class JukeBox:
    def __init__(self):
        self.__songs : List[Song] = []
        self.__playlist : List[Playlist] = []

    def add_song_to_juke_box(self, song : Song):
        '''
            Function for adding the song to juke box
        '''
        self.__songs.append(song)
    
    def add_playlist_to_juke_box(self, playlist : Playlist):
        '''
            Function for adding the playlist to the juke box
        '''
        self.__playlist.append(playlist)
    
    def play_song(self, name : str):
        '''
            Function for playing the song
        '''
        song_to_be_played : Song = None
        for song in self.__songs:
            if song.get_song_name() == name:
                song_to_be_played = song
                break
    
        song_to_be_played.play_song()

    def play_playlist(self, playlist_name : str):
        '''
            Function for playing the songs in the playlist
        '''
        playlist_to_be_played : Playlist = None
        for playlist in self.__playlist:
            if playlist.get_playlist_name() == playlist_name:
                playlist_to_be_played = playlist
                break

        playlist_songs : List[Song] = playlist_to_be_played.get_playlist_songs()
        for song in playlist_songs:
            song.play_song()

juke_box = JukeBox()

artist_1 = Artist("Manish")
artist_2 = Artist("Soni")

song = Song("ABC", [artist_1, artist_2])

playlist = Playlist("playlist1")
playlist.add_song_to_playlist(song)

juke_box.add_song_to_juke_box(song)
juke_box.add_playlist_to_juke_box(playlist)

juke_box.play_song(song.get_song_name())

juke_box.play_playlist("playlist1")
