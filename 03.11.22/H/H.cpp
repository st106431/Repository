#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	char* s = new char[max(n + 1, (long long)10)];
	long long* a = new long long[max(n + 1, (long long)10)];
	long long* b = new long long[max(n + 1, (long long)10)];
	int* pr = new int[max(n + 1, (long long)10)];
 	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	a[1] = 0;
	b[1] = 0;
	a[2] = n + 1;
	b[2] = -1;
	pr[2] = -1;
	if (s[3] != 'w')
	{
		a[3] = 1;
		if (s[3] == '"')
		{
			b[3] = 1;
		}
		else
		{
			b[3] = 0;
		}
	}
	else
	{
		a[3] = n + 1;
		b[3] = -1;
	}
	pr[3] = 1;
	for (int i = 4; i <= 6; i++)
	{
		if(s[i] != 'w')
		{
			a[i] = min(a[i - 3], a[i - 2]);
			if (a[i] == n + 1)
			{
				b[i] = -1;
				pr[i] = -1;
			}
			else
			{
				if (a[i - 3] != a[i - 2])
				{
					if (a[i] == a[i - 2])
					{
						pr[i] = i - 2;
						if (s[i] == '"')
						{
							b[i] = b[i - 2] + 1;
						}
						else
						{
							b[i] = b[i - 2];
						}
					}
					else
					{
						pr[i] = i - 3;
						if (s[i] == '"')
						{
							b[i] = b[i - 3] + 1;
						}
						else
						{
							b[i] = b[i - 3];
						}
					}
				}
				else
				{
					if (b[i - 2] >= b[i - 3])
					{
						pr[i] = i - 2;
						if (s[i] == '"')
						{
							b[i] = b[i - 2] + 1;
						}
						else
						{
							b[i] = b[i - 2];
						}
					}
					else
					{
						pr[i] = i - 3;
						if (s[i] == '"')
						{
							b[i] = b[i - 3] + 1;
						}
						else
						{
							b[i] = b[i - 3];
						}
					}
				}
				if (a[i] != n + 1)
				{
					a[i]++;
				}
			}
		}
		else
		{
			a[i] = n + 1;
			b[i] = -1;
			pr[i] = -1;
		}
	}
	for (int i = 7; i <= n; i++)
	{
		int k = 0;
		bool mas[3]{ 0 };
		if (s[i] != 'w')
		{
			a[i] = min(min(a[i - 3], a[i - 2]), a[i - 6]);
			if (a[i] == n + 1)
			{
				b[i] = -1;
				pr[i] = -1;
			}
			else
			{
				if (a[i - 2] == a[i - 3])
				{
					k++;
					mas[0] = 1;
				}
				if (a[i - 2] == a[i - 6])
				{
					k++;
					mas[1] = 1;
				}
				if (a[i - 3] == a[i - 6])
				{
					k++;
					mas[2] = 1;
				}
				if (k == 0)
				{
					if (a[i] == a[i - 2])
					{
						b[i] = b[i - 2];
						pr[i] = i - 2;
					}
					if (a[i] == a[i - 3])
					{
						b[i] = b[i - 3];
						pr[i] = i - 3;
					}
					if (a[i] == a[i - 6])
					{
						b[i] = b[i - 6];
						pr[i] = i - 6;
					}
					if (s[i] == '"')
					{
						b[i]++;
					}
					a[i]++;
				}
				else
				{
					if (k == 1)
					{
						if (mas[0] == 1)
						{
							if (a[i - 2] != n + 1)
							{
								if (a[i] == a[i - 2])
								{
									a[i] = a[i - 2] + 1;
									if (b[i - 2] >= b[i - 3])
									{
										b[i] = b[i - 2];
										pr[i] = i - 2;
									}
									else
									{
										b[i] = b[i - 3];
										pr[i] = i - 3;
									}
								}
								else
								{
									a[i] = a[i - 6] + 1;
									b[i] = b[i - 6];
									pr[i] = i - 6;
								}
							}
							else
							{
								a[i] = a[i - 6] + 1;
								b[i] = b[i - 6];
								pr[i] = i - 6;
							}
						}
						else
						{
							if (mas[1] == 1)
							{
								if (a[i - 2] != n + 1)
								{
									if (a[i] == a[i - 2])
									{
										a[i] = a[i - 2] + 1;
										if (b[i - 2] >= b[i - 6])
										{
											b[i] = b[i - 2];
											pr[i] = i - 2;
										}
										else
										{
											b[i] = b[i - 6];
											pr[i] = i - 6;
										}
									}
									else
									{
										a[i] = a[i - 3] + 1;
										b[i] = b[i - 3];
										pr[i] = i - 3;
									}
								}
								else
								{
									a[i] = a[i - 3] + 1;
									b[i] = b[i - 3];
									pr[i] = i - 3;
								}
							}
							else
							{
								if (a[i - 6] != n + 1)
								{
									if (a[i] == a[i - 6])
									{
										a[i] = a[i - 6] + 1;
										if (b[i - 3] >= b[i - 6])
										{
											b[i] = b[i - 3];
											pr[i] = i - 3;
										}
										else
										{
											b[i] = b[i - 6];
											pr[i] = i - 6;
										}
									}
									else
									{
										a[i - 3], a[i - 6];
										a[i] = a[i - 2] + 1;
										b[i] = b[i - 2];
										pr[i] = i - 2;
									}
								}
								else
								{
									a[i] = a[i - 2] + 1;
									b[i] = b[i - 2];
									pr[i] = i - 2;
								}
							}
						}
						if (s[i] == '"')
						{
							b[i]++;
						}
					}
					else
					{
						a[i] = a[i - 2] + 1;
						if (b[i - 2] >= b[i - 3])
						{
							if (b[i - 2] >= b[i - 6])
							{
								b[i] = b[i - 2];
								pr[i] = i - 2;
							}
							else
							{
								b[i] = b[i - 6];
								pr[i] = i - 6;
							}
						}
						else
						{
							if (b[i - 6] >= b[i - 3])
							{
								b[i] = b[i - 6];
								pr[i] = i - 6;
							}
							else
							{
								b[i] = b[i - 3];
								pr[i] = i - 3;
							}
						}
						if (s[i] == '"')
						{
							b[i]++;
						}
					}
				}
			}
		}
		else
		{
			a[i] = n + 1;
			b[i] = -1;
			pr[i] = -1;
		}
	}
	if (a[n] != n + 1)
	{
		cout << a[n] << " " << b[n] << endl;
		int i = n;
		int* st = new int[a[n]];
		int k = a[n] - 1;
		while (i != 1)
		{
			st[k] = pr[i];
			k--;
			i = pr[i];
		}
		for (int j = 0; j < a[n]; j++)
		{
			cout << st[j] << " ";
		}
		cout << n << " ";
	}
	else
	{
		cout << -1;
	}
}