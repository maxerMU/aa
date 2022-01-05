#include "levenstein.hpp"

#include "matrix.hpp"

size_t matr_method(const string &str1, const string &str2) {
  size_t n = str1.length() + 1, m = str2.length() + 1;
  auto mtr = Matrix<size_t>(n, m);

  for (size_t i = 0; i < m; i++)
    mtr[0][i] = i;

  for (size_t i = 0; i < n; i++)
    mtr[i][0] = i;

  for (size_t i = 1; i < n; i++)
    for (size_t j = 1; j < m; j++) {
      mtr[i][j] = min(min(mtr[i - 1][j] + 1, mtr[i][j - 1] + 1),
                      mtr[i - 1][j - 1] + (str1[i - 1] == str2[j - 1] ? 0 : 1));
    }

  return mtr[n - 1][m - 1];
}

size_t recur(const string &str1, const size_t len1, const string &str2,
             const size_t len2) {
  if (len1 == len2 && len1 == 0) {
    return 0;
  } else if (len1 == 0) {
    return len2;
  } else if (len2 == 0) {
    return len1;
  } else {
    bool flag = str1[len1 - 1] != str2[len2 - 1];
    return min(min(recur(str1, len1 - 1, str2, len2) + 1,
                   recur(str1, len1, str2, len2 - 1) + 1),
               recur(str1, len1 - 1, str2, len2 - 1) + flag);
  }
}

size_t recur_method(const string &str1, const string &str2) {
  size_t len1 = str1.length(), len2 = str2.length();
  return recur(str1, len1, str2, len2);
}

size_t rec_cache(const string &str1, const size_t len1, const string &str2,
                 const size_t len2, Matrix<size_t> &mtr) {
  if (mtr[len1][len2] != 0) {
    return mtr[len1][len2];
  } else if (len1 == len2 && len1 == 0) {
    mtr[len1][len2] = 0;
  } else if (len1 == 0) {
    mtr[len1][len2] = len2;
  } else if (len2 == 0) {
    mtr[len1][len2] = len1;
  } else {
    bool flag = str1[len1 - 1] != str2[len2 - 1];
    mtr[len1][len2] =
        min(min(rec_cache(str1, len1 - 1, str2, len2, mtr) + 1,
                rec_cache(str1, len1, str2, len2 - 1, mtr) + 1),
            rec_cache(str1, len1 - 1, str2, len2 - 1, mtr) + flag);
  }
  return mtr[len1][len2];
}

size_t rec_cache_method(const string &str1, const string &str2) {
  size_t len1 = str1.length(), len2 = str2.length();
  auto mtr = Matrix<size_t>(len1 + 1, len2 + 1);

  for (size_t i = 0; i < len1 + 1; i++)
    for (size_t j = 0; j < len2 + 1; j++)
      mtr[i][j] = 0;

  size_t result = rec_cache(str1, len1, str2, len2, mtr);

  return result;
}

size_t Domerau(const string &str1, const size_t len1, const string &str2,
               const size_t len2, Matrix<size_t> &mtr) {
  if (mtr[len1][len2] != 0) {
    return mtr[len1][len2];
  } else if (len1 == len2 && len1 == 0) {
    mtr[len1][len2] = 0;
  } else if (len1 == 0) {
    mtr[len1][len2] = len2;
  } else if (len2 == 0) {
    mtr[len1][len2] = len1;
  } else {
    if (len1 > 1 && len2 > 1 && str1[len1 - 2] == str2[len2 - 1] &&
        str1[len1 - 1] == str2[len2 - 2]) {
      mtr[len1][len2] = min(Domerau(str1, len1 - 2, str2, len2 - 2, mtr) + 1,
                            mtr[len1][len2]);
    } else {
      bool flag = str1[len1 - 1] != str2[len2 - 1];
      mtr[len1][len2] =
          min(min(Domerau(str1, len1 - 1, str2, len2, mtr) + 1,
                  Domerau(str1, len1, str2, len2 - 1, mtr) + 1),
              Domerau(str1, len1 - 1, str2, len2 - 1, mtr) + flag);
    }
  }

  return mtr[len1][len2];
}

size_t Domerau_method(const string &str1, const string &str2) {
  size_t len1 = str1.length(), len2 = str2.length();
  auto mtr = Matrix<size_t>(len1 + 1, len2 + 1);

  for (size_t i = 0; i < len1 + 1; i++)
    for (size_t j = 0; j < len2 + 1; j++)
      mtr[i][j] = 0;

  Domerau(str1, len1, str2, len2, mtr);

  size_t result = mtr[len1][len2];

  return result;
}
