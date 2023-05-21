login(){
	lr_start_transaction("login");
	
	web_reg_find("Text/IC=Welcome, <b>{username}</b>, to the Web Tours reservation pages.",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={username}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=0", ENDITEM,
		"Name=login.y", "Value=0", ENDITEM,
		LAST);
	lr_end_transaction("login",LR_AUTO);
}

open_homepage (){
	lr_start_transaction("open_homepage");
	
	/*Correlation comment - Do not change!  Original value='136391.383718105HAVfzDVpitcAQDpHQAi' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
	
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../favicon.ico", "Referer=", ENDITEM, 
		LAST);
	
	lr_end_transaction("open_homepage", LR_AUTO);
}

click_flight(){
	lr_start_transaction("click_Flights");
	
	web_reg_find("Text/IC=<title>Flight Selections</title>",
		LAST);
	
	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_Flights",LR_AUTO);
}

find_flights(){
	lr_start_transaction("Find_Flight");
	
	web_reg_find("Text/IC=Flight departing from <B>{depart_city}</B> to <B>{arrive_city}</B> on <B>{depart_date}<",
		LAST);

	
	web_reg_save_param("outboundFlight",
		"LB/IC=name=\"outboundFlight\" value=\"",
		"RB/IC=\"",
		"ORD=random",
		LAST);
	
	web_reg_save_param("returnFlight",
		"LB/IC=name=\"returnFlight\" value=\"",
		"RB/IC=\"",
		"ORD=random",
		LAST);
	
	
	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart_city}", ENDITEM, 
		"Name=departDate", "Value={depart_date}", ENDITEM, 
		"Name=arrive", "Value={arrive_city}", ENDITEM, 
		"Name=returnDate", "Value={return_date}", ENDITEM, 
		"Name=numPassengers", "Value={count_pass}", ENDITEM,
		"Name=roundtrip", "Value={round_trip}", ENDITEM, 		
		"Name=seatPref", "Value={seat_pref}", ENDITEM,
		"Name=seatType", "Value={seat_type}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=74", ENDITEM, 
		"Name=findFlights.y", "Value=14", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_end_transaction("Find_Flight",LR_AUTO);
}

choose_flight(){
	lr_start_transaction("Choose_Flight");
	
	web_reg_find("Text/IC=<b>Payment Details</font></b>",
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=returnFlight", "Value={returnFlight}", ENDITEM,		
		"Name=numPassengers", "Value={count_pass}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=49", ENDITEM, 
		"Name=reserveFlights.y", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("Choose_Flight",LR_AUTO);
}

click_itinerary(){
	lr_start_transaction("click_Itinerary");

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_Itinerary",LR_AUTO);
}
logout(){
lr_start_transaction("Logout");
	
	web_reg_find("Text/IC=Welcome to the Web Tours site.",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);
	}
