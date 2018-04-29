main:
	g++ -o "homework5" main.cpp

debug: 
	g++ -o "homework5" main.cpp -D DEBUG
	
clean:
	rm -f "homework5"
