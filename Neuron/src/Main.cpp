#include <iostream>

//Perceptron		

template<int inputs>
class Perceptron
{
public:
	Perceptron(float weights[inputs], float b = 0.0f)
		: bias(b)
	{
		memcpy(w, weights, inputs * sizeof(float));
	};
	~Perceptron() {};

	float CalculateOutput(float x[inputs]);
	//void Learn(int count, float x[][inputs], float* y, float a = 1.0f); //calculate Weights

private:
	float uebertragungsfunktion(float x[inputs]);
	float schwellenwertfunktion(float x);
	float w[inputs]; //Weights
	float bias;
};


template<int inputs>
float Perceptron<inputs>::CalculateOutput(float x[inputs])
{
	return schwellenwertfunktion(uebertragungsfunktion(x));
}

/*
template<int inputs>
void Perceptron<inputs>::Learn(int count, float x[][inputs], float* y, float a)	 //Lerngeschwindigkeitskoeffizient
{
	for (int j = 0; j < count; j++)
	{
		float out = CalculateOutput(x[j]);
		for (int i = 0; i < inputs; i++)
			w[i] = w[i] + a * (y[j] - out) * x[j][i];
	}
}

*/
template<int inputs>
float Perceptron<inputs>::uebertragungsfunktion(float x[inputs])
{
	float sum = 0.0f;
	for (int i = 0; i < inputs; i++)
		sum += x[i] * w[i];
	return sum + bias;
}

template<int inputs>
float Perceptron<inputs>::schwellenwertfunktion(float x)
{
	return (x > 0) ? 1 : 0;
}

int main()
{
	float weights[2] = { -2.0f, -2.0f };
	float bias = 3.0f;
	float x[2] = { 1.0f, 1.0f };

	Perceptron<2> neuron(weights, bias);

	std::cout << neuron.CalculateOutput(x) << std::endl;
	std::cin.get();
	return 0;
}

