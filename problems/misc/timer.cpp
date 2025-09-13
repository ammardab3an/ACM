struct timer{
	
	std::chrono::_V2::system_clock::time_point t;
	
	timer(){
		t = high_resolution_clock::now();
	}
	
	~timer(){
		auto nt = high_resolution_clock::now();
		auto d = duration_cast<milliseconds>(nt - t);
		cerr << d.count() << endl;
	}
};
