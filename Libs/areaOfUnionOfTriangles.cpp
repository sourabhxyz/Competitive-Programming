struct segment {
	int x1, y1, x2, y2;
};

struct point {
	double x, y;
};

struct item {
	double y1, y2;
	int triangle_id;
};

struct line {
	int a, b, c;
};

const double EPS = 1E-7;

void intersect (segment s1, segment s2, vector<point> & res) {
	line l1 = { s1.y1-s1.y2, s1.x2-s1.x1, l1.a*s1.x1+l1.b*s1.y1 },
		l2 = { s2.y1-s2.y2, s2.x2-s2.x1, l2.a*s2.x1+l2.b*s2.y1 };
	double det1 = l1.a * l2.b - l1.b * l2.a;
	if (abs (det1) < EPS)  return;
	point p = { (l1.c * 1.0 * l2.b - l1.b * 1.0 * l2.c) / det1,
		(l1.a * 1.0 * l2.c - l1.c * 1.0 * l2.a) / det1 };
	if (p.x >= s1.x1-EPS && p.x <= s1.x2+EPS && p.x >= s2.x1-EPS && p.x <= s2.x2+EPS)
		res.push_back (p);
}

double segment_y (segment s, double x) { // just gives us the ordinate corresponding to x on segment
	return s.y1 + (s.y2 - s.y1) * (x - s.x1) / (s.x2 - s.x1);
}

bool eq (double a, double b) {
	return abs (a-b) < EPS;
}

vector<item> c;

bool cmp_y1_y2 (int i, int j) {
	const item & a = c[i];
	const item & b = c[j];
	return a.y1 < b.y1-EPS || abs (a.y1-b.y1) < EPS && a.y2 < b.y2-EPS;
}

int main() {

	int n;
	cin >> n;
	vector<segment> a (n*3);
	for (int i=0; i<n; ++i) {
		int x1, y1, x2, y2, x3, y3;
		scanf ("%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3);
		segment s1 = { x1,y1,x2,y2 };
		segment s2 = { x1,y1,x3,y3 };
		segment s3 = { x2,y2,x3,y3 };
		a[i*3] = s1;
		a[i*3+1] = s2;
		a[i*3+2] = s3;
	}

	for (size_t i=0; i<a.size(); ++i)
		if (a[i].x1 > a[i].x2)
			swap (a[i].x1, a[i].x2),  swap (a[i].y1, a[i].y2);

	vector<point> b;
	b.reserve (n*n*3);
	// Number of distinct intersection points can be atmost (3 * n * n), as an example, take just
	// 2 inverted triangles
	for (size_t i=0; i<a.size(); ++i)
		for (size_t j=i+1; j<a.size(); ++j)
			intersect (a[i], a[j], b); // Getting all the segment intersection points

	vector<double> xs (b.size());
	for (size_t i=0; i<b.size(); ++i)
		xs[i] = b[i].x; // Getting the absicca of the intersection points
	sort (xs.begin(), xs.end()); // sorting them, so that any subsequent xs[i] and xs[i + 1] define a
	// vertical strip where which we will get a trapezoid since there would be by definition no
	// intersections in this region.
	xs.erase (unique (xs.begin(), xs.end(), &eq), xs.end()); // Having only unique points
	// as different intersection points can have the same x coordinate
	// Maybe it would have been better to define the equality operator in the struct point
	double res = 0;
	vector<char> used (n);
	vector<int> cc (n*3);
	c.resize (n*3);
	for (size_t i=0; i+1<xs.size(); ++i) {
		double x1 = xs[i],  x2 = xs[i+1]; // Getting our vertical region
		size_t csz = 0; // initialised each time to zero
		for (size_t j=0; j<a.size(); ++j)
			if (a[j].x1 != a[j].x2) // Verticle lines (segments) are ignored
				if (a[j].x1 <= x1+EPS && a[j].x2 >= x2-EPS) { // i.e. segment should encompass equal or more width than the width of vertical region. i.e. line making up our vertical region lies within this segment.
					item it = { segment_y (a[j], x1), segment_y (a[j], x2), (int)j/3 };
					cc[csz] = (int)csz;
					c[csz++] = it;
				}
		sort (cc.begin(), cc.begin()+csz, &cmp_y1_y2); // y1 will always be the left y intersection.
		// we are sorting such that first we want y1 to be below and if there is equality then y2 to be below. Thus now we will be starting from below.
		double add_res = 0;
		for (size_t j=0; j<csz; ) {
			item lower = c[cc[j++]];
			used[lower.triangle_id] = true;
			int cnt = 1;  // denotes our current number of open triangles i.e. we have opened this segment of triangle but haven't yet found its counterpart.
			// Clearly due to our sorting and the way below algo is written, we wont consider area between high (upper) of one segment and lower of the segment above it.
			// Now for a particular region, if there are many triangles crossing that region, we want to take the lowest of one triangle and highest of other triangle.
			while (cnt && j<csz) {
				char &cur = used[c[cc[j++]].triangle_id]; // Notice that it is &cur
				// clearly for any closed figure, if there is one segment crossing some x region,
				// there will exist other one crossing the same x region, so our aim is to
				// get the topmost and the bottom most of such segments
				cur = !cur;
				if (cur)  ++cnt;  else  --cnt;
			}
			item upper = c[cc[j-1]];
			add_res += upper.y1 - lower.y1 + upper.y2 - lower.y2;
		}
		res += add_res * (x2 - x1) / 2;
	}

	cout.precision (8);
	cout << fixed << res;

}
