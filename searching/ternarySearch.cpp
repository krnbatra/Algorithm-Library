double ternarySearch(){
	double minn = a;
	double maxx = b;
	while(maxx-minn > EPS){
		g = minn + (maxx-minn)/3;
		h = minn + 2*(maxx-minn)/3;
		if(f(g) < f(h))
			maxx = h;
		else
			minn = g;
	}
	return (maxx+minn)/2;
}