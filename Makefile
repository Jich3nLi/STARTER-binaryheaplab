examheap: examheap.cpp heap.cpp
	g++ -std=c++17 examheap.cpp heap.cpp -o examheap

clean:
	rm -f examheap
