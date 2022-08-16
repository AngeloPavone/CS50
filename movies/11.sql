SELECT title
FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN ratings ON ratings.movie_id = stars.movie_id
JOIN people on people.id = stars.person_id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC LIMIT 5;
