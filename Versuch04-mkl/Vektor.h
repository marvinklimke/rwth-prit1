//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 04: Einf�hrung in die Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//
// Autor:  Marvin Klimke
// Matr.:  000000
// Datum:  21.04.2016
//////////////////////////////////////////////////////////////////////////////

#ifndef Vektor_H
#define Vektor_H

/**
 * \brief Vektor-class holds the values for a 3-dimensional vector
 */
class Vektor
{
   public: //Konstruktor/Destruktor
	/**
	 * \brief The constructor of Vektor class
	 * \param x the x-coordinate
	 * \param y the y-coordinate
	 * \param z the z-coordinate
	 */
      Vektor(double x, double y, double z);

      /**
       * \brief The standard destructor
       */
      ~Vektor();

   private: //member
      double x;
      double y;
      double z;

   public:

      /**
       * \brief This function prints the values of the 3-dimensional vector to the console.
       */
      void ausgabe() const;

      /**
       * \return the x-value
       */
      double getX() const;

      /**
       * \return the y-value
       */
      double getY() const;

      /**
       * \return the z-value
       */
      double getZ() const;

      /**
       * \return the length of the vector
       */
      double getLength() const;

      /**
       * \brief This function subtracts a vector v from the object and returns the result
       * \param v the vector to subtract from the object
       * \return the vector given by the difference between the object and v
       */
      Vektor subtract(const Vektor& v) const;

      /**
       * \brief This function calculates the sum of two vectors
       * \param v1 vector to add
       * \return sum of v1 and v2
       */
      Vektor add(const Vektor& v) const;

      /**
       * \brief This function calculates the scalar-product of two vectors
       * \param v1 vector to calculate scalar-product
       * \return scalar-product of v1 and v2
       */
      double scalar(const Vektor v) const;

      /**
       * \brief This function checks whether the vectors v1 and v2 are orthogonal
       * \param v1 vector to check
       * \return true if the two vectors are orthogonal, false otherwise
       */
      bool isOrthogonal(const Vektor v) const;

      /**
       * \brief This function rotates a vector (the object) around the Z-axis with the given angle
       * \param rad The angle to rotate with
       */
      void rotate(const double rad);

};

#endif
