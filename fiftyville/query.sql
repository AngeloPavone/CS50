SELECT name,phone_number FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN passengers ON passengers.passport_number = people.passport_number

WHERE person_id IN (
    SELECT person_id FROM bank_accounts WHERE account_number IN (
        SELECT account_number amount FROM atm_transactions WHERE day = "28" and atm_location = "Leggett Street" and transaction_type = "withdraw")
)
AND
bakery_security_logs.license_plate IN (
    SELECT bakery_security_logs.license_plate FROM bank_accounts WHERE bakery_security_logs.hour = "10" AND bakery_security_logs.day = "28"
)
AND
phone_calls.caller IN (
    SELECT phone_calls.caller FROM phone_calls WHERE phone_calls.duration < "60" AND phone_calls.day = "28"
)
AND
passengers.passport_number IN (
    SELECT passengers.passport_number FROM passengers WHERE passengers.flight_id = "36"
)

GROUP BY name
;
