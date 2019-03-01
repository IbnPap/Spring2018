make:  System_call context_switch 

sc:
	gcc -o cs 	System_call.c 

cs:  
	gcc -o	cs 	context_switch.c