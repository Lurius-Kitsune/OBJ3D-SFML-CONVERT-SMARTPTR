#include "Color.h"

// === Gradient === 
string Gradient::GradientString(const string& _text, const bool _textOnly) const
{
    const int _size = CAST(int, _text.size());
    string _newWord = string();

    for (int _index = 0; _index < _size; _index++)
    {
        const ColorData& _color = ClampGradient(_index, _size);
        _newWord += _color.ToString(_textOnly) + _text[_index];
    }

    return _newWord + COLOR_RESET;
}

ColorData Gradient::ClampGradient(const int _index, const int _maxDisplayChar) const
{
    float _normalizer = 0.0f;
    float _valueRed = 0.0f;
    float _valueGreen = 0.0f;
    float _valueBlue = 0.0f;

    const float _rangeRed = CAST(float, gradB.r - gradA.r);
    _normalizer = _index * (_rangeRed / _maxDisplayChar);
    _valueRed += (gradA.r + _normalizer);

    const float _rangeGreen = CAST(float, gradB.g - gradA.g);
    _normalizer = _index * (_rangeGreen / _maxDisplayChar);
    _valueGreen += (gradA.g + _normalizer);

    const float _rangeBlue = CAST(float, gradB.b - gradA.b);
    _normalizer = _index * (_rangeBlue / _maxDisplayChar);
    _valueBlue += (gradA.b + _normalizer);

    return { 
        CAST(int, _valueRed), 
        CAST(int, _valueGreen), 
        CAST(int, _valueBlue) 
    };
}