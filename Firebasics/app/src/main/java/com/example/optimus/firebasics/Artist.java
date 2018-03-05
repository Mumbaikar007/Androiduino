package com.example.optimus.firebasics;

/**
 * Created by optimus on 2/3/18.
 */

public class Artist {

    public String artistId, artistName, artistGenre;

    public Artist (){

    }

    public Artist(String artistId, String artistName, String artistGenre) {
        this.artistId = artistId;
        this.artistName = artistName;
        this.artistGenre = artistGenre;
    }

    public String getArtistId() {
        return artistId;
    }

    public String getArtistName() {
        return artistName;
    }

    public String getArtistGenre() {
        return artistGenre;
    }
}
