# 30-3-queries-with-arguments

Make a request to the httpbin.org service, sending several additional data arguments.
All argument names and their values are strings and are received from the user.
The user sequentially enters their names along with the values until an argument called “post” or “get” is encountered, which will mean that entering the arguments is finished and they need to be sent to the server in the chosen way.
If the user selects “post”, then a POST request is made and the arguments are sent in the POST way (as a form).
If “get”, then a GET request is executed with GET arguments (directly in the URL).
Based on the results of the request, output the server response to the standard console and pay attention to the form or args fields, depending on the type of request, which should list all the arguments you entered.
