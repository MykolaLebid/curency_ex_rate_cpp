#curl --request GET --url 'https://api.ratesapi.io/api/history?start_at=2018-01-01&end_at=2018-01-03&base=EUR&symbols=USD' -o results 
#curl -v --request GET --url 'https://api.ratesapi.io/api/latest?base=EUR&symbols=USD' -o results_1 --libcurl request.c

curl -v GET --url 'https://api.ratesapi.io/api/latest?base=EUR&symbols=USD' --libcurl request.c
#curl -v --request GET --url 'https://www.google.com/' -o res
