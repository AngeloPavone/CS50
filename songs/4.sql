SELECT name FROM songs GROUP BY name HAVING min(danceability, energy, valence) > .75;
