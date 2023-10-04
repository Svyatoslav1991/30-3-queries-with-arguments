#include <iostream>
#include <cpr/cpr.h>
#include <map>
#include <string>
#include <sstream>


cpr::Response performGetRequest(const std::map<std::string, std::string>& arguments) noexcept;
cpr::Response performPostRequest(const std::map<std::string, std::string>& arguments) noexcept;

int main()
{
	std::cout << "\tTASK 30.3 QUERIES WITH ARGUMENTS\n\n";

	std::map<std::string, std::string> arguments;

	std::string name, value;

	while (true)
	{
		std::cout << "Enter the argument name (or 'post'/'get' to send the request): ";
		std::cin >> name;

		if (name == "post" || name == "get")
		{
			break;
		}

		std::cout << "Enter the argument value: ";
		std::cin >> value;

		arguments[name] = value;
	}

	cpr::Response r;

	if (name == "post")
	{
		r = performPostRequest(arguments);
		std::cout << "Response to POST request:\n" << r.text << "\n";
	}
	else
	{
		r = performGetRequest(arguments);
		std::cout << "Response to GET request:\n" << r.text << "\n";
	}


	return 0;
}

//-------------------------------------------------------------------------------------------------------

cpr::Response performGetRequest(const std::map<std::string, std::string>& arguments) noexcept
{
	std::stringstream url;
	url << "https://httpbin.org/get?";
	for (auto it = arguments.cbegin(); it != arguments.cend(); ++it)
	{
		url << it->first << "=" << it->second << "&";
	}
	url.seekp(-1, std::ios_base::end);

	return cpr::Get(cpr::Url(url.str()));
}

//-------------------------------------------------------------------------------------------------------

cpr::Response performPostRequest(const std::map<std::string, std::string>& arguments) noexcept
{
	cpr::Parameters parameters;
	for (auto it = arguments.cbegin(); it != arguments.cend(); ++it)
	{
		parameters.Add({ it->first, it->second });
	}

	return cpr::Post(cpr::Url("https://httpbin.org/post"), parameters);
}
