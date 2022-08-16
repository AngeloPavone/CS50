-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time
-– each of their interview transcripts mentions the bakery.

-- See what we are working with
SELECT description FROM crime_scene_reports;

-- List all thefts rather then random crimes
SELECT description FROM crime_scene_reports WHERE description LIKE "%theft%";                                                                                               --"

-- Show time and location of all the theft crimes
SELECT description, street, day, month, year FROM crime_scene_reports WHERE description LIKE "%theft%";
-- We learned that there are 3 witnesses that mention the bakery in their interviews and that the theft happend at 10:15am

-- Get calls on the 28th
SELECT day, month, year, duration FROM phone_calls WHERE day = "28";

-- Attempting to get a list of all the phone calls on the 28th that where very short because if you are calling your accomplice you arnt going to chat for a long time (i was hoping to see a few repeat short calls from the same number)
select caller, duration, receiver from phone_calls where duration < "70" AND day = (SELECT day from phone_calls where day = "28") group by caller;

-- Read inverviews since my above "shortcut" didnt seem to bare any fruit
SELECT transcript FROM interviews WHERE day = "28";

-- Get list of calls that are less than 60s
select caller, duration, receiver from phone_calls where duration < "60" AND day = (SELECT day from phone_calls where day = "28") group by caller;
-- need to check the first flight out of Fiftyville on the 29th
--      full_name                                id
--      ---------------------------------------  --
--      O'Hare International Airport             1
--      Beijing Capital International Airport    2
--      Los Angeles International Airport        3
--      LaGuardia Airport                        4 <-- destination_airport_id of first flight out of Fiftyville on the 29th
--      Dallas/Fort Worth International Airport  5
--      Logan International Airport              6
--      Dubai International Airport              7
--      Fiftyville Regional Airport              8 <-- Fiftyville airport id
--      Tokyo International Airport              9
--      Charles de Gaulle Airport                10
--      San Francisco International Airport      11
--      Indira Gandhi International Airport      12
--      get info on person that booked it.

--      caller          duration  receiver
--      --------------  --------  --------------
--      (031) 555-6622  38        (910) 555-3251
--      (130) 555-0289  51        (996) 555-8899
--      (286) 555-6063  43        (676) 555-6554
--      (338) 555-6650  54        (704) 555-2131
--      (367) 555-5533  45        (375) 555-8161
--      (499) 555-9472  36        (892) 555-8872
--      (770) 555-1861  49        (725) 555-3243
--      (826) 555-1652  55        (066) 555-9701
name    phone_number
------  --------------
Bruce   (367) 555-5533
Taylor  (286) 555-6063

-- get flights out of Fiftyville on the 29th
select id from flights where day = "29" AND ;

--      id  origin_airport_id  hour  minute  destination_airport_id
--      --  -----------------  ----  ------  ----------------------
--      18  8                  16    0       6
--      23  8                  12    15      11
--      36  8                  8     20      4 <-- the flight in question
--      43  8                  9     30      1
--      53  8                  15    20      9

-- get city name
select full_name, city from airports where id = "4";

-- license_plate of people that exited within 10am on the 28th
select hour, minute, license_plate, activity from bakery_security_logs where hour = "10" AND day = (select day from bakery_security_logs where day = "28")order by minute;

--      hour  minute  license_plate  activity
--      ----  ------  -------------  --------
--      10    18      6P58WS2        exit
--      10    19      4328GD8        exit
--      10    20      G412CB7        exit
--      10    21      L93JTIZ        exit
--      10    23      322W7JE        exit
--      10    23      0NTHK55        exit

-- Shitty way to find the phone / passport of all the people that match the license_plates above there is only a few though so oh well
select name, phone_number, passport_number from people where license_plate IN ("6P58WS2", "4328GD8", "G412CB7", "L93JTIZ", "322W7JE", "0NTHK55");

--      name    phone_number    passport_number
--      ------  --------------  ---------------
--      Barry   (301) 555-4174  7526138472
--      Iman    (829) 555-5269  7049073643
--      Sofia   (130) 555-0289  1695452385
--      Luca    (389) 555-5198  8496433585
--      Diana   (770) 555-1861  3592750733
--      Kelsey  (499) 555-9472  8294398571

-- Get transations
select transaction_type, account_number, amount from atm_transactions where day = "28" and atm_location = "Leggett Street";
--      transaction_type  account_number  amount
--      ----------------  --------------  ------
--      withdraw          28500762        48
--      withdraw          28296815        20
--      withdraw          76054385        60
--      withdraw          49610011        50
--      withdraw          16153065        80
--      deposit           86363979        10
--      withdraw          25506511        20
--      withdraw          81061156        30
--      withdraw          26013199        35

select * from bank_accounts where account_number IN (select account_number amount from atm_transactions where day = "28" and atm_location = "Leggett Street" and transaction_type = "withdraw");
--      account_number  person_id  creation_year
--      --------------  ---------  -------------
--      49610011        686048     2010
--      26013199        514354     2012
--      16153065        458378     2012
--      28296815        395717     2014
--      25506511        396669     2014
FROM people
--      28500762        467400     2014
--      76054385        449774     2015
--      81061156        438727     2018

-- wit1: [x] Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

    i got a list of license_plates

-- wit2: [x] I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

    got a account number, person id.

-- wit3: [x] As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
    -- The thief then asked the person on the other end of the phone to purchase the flight ticket.

    i got the flight they took
