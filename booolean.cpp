//==================================================================================
// BSD 2-Clause License
//
// Copyright (c) 2014-2022, NJIT, Duality Technologies Inc. and other contributors
//
// All rights reserved.
//
// Author TPOC: contact@openfhe.org
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//==================================================================================

/*
  Example for the FHEW scheme using the default bootstrapping method (GINX)
 */

#include "binfhecontext.h"
#include <algorithm>

using namespace lbcrypto;
using namespace std;

std::vector<bool> adder(bool i, bool j, bool carry) {
    // Sample Program: Step 1: Set CryptoContext
    std::vector<bool> sumcarry;
    auto cc = BinFHEContext();

    // STD128 is the security level of 128 bits of security based on LWE Estimator
    // and HE standard. Other common options are TOY, MEDIUM, STD192, and STD256.
    // MEDIUM corresponds to the level of more than 100 bits for both quantum and
    // classical computer attacks.
    cc.GenerateBinFHEContext(STD128);

    // Sample Program: Step 2: Key Generation

    // Generate the secret key
    auto sk = cc.KeyGen();

    std::cout << "Generating the bootstrapping keys..." << std::endl;

    // Generate the bootstrapping keys (refresh and switching keys)
    cc.BTKeyGen(sk);

    std::cout << "Completed the key generation." << std::endl;

    // Sample Program: Step 3: Encryption

    // Encrypt two ciphertexts representing Boolean True (1).
    // By default, freshly encrypted ciphertexts are bootstrapped.
    // If you wish to get a fresh encryption without bootstrapping, write
    // auto   ct1 = cc.Encrypt(sk, 1, FRESH);
    auto ct1 = cc.Encrypt(sk, i);
    auto ct2 = cc.Encrypt(sk, j);
    auto ct3 = cc.Encrypt(sk, carry);

    // Sample Program: Step 4: Evaluation

    // Compute (1 AND 1) = 1; Other binary gate options are OR, NAND, and NOR
    // 1st stage: c1
    auto ctAND1 = cc.EvalBinGate(AND, ct1, ct2);  //carry

    // Compute (1 AND 1) = 1; Other binary gate options are OR, NAND, and NOR
    // s1
    auto ctXOR1 = cc.EvalBinGate(XOR, ct1, ct2);  //sum

    // 2nd stage: c2
    auto ctAND2 = cc.EvalBinGate(AND, ctXOR1, ct3);  //carry

    // Compute (1 AND 1) = 1; Other binary gate options are OR, NAND, and NOR
    // s2
    auto ctXOR2 = cc.EvalBinGate(XOR, ctXOR1, ct3);  //sum

    // 3rd Stage: s3
    auto ctXOR3 = cc.EvalBinGate(XOR, ctAND1, ctAND2);  //final carry

    LWEPlaintext res1;

    cc.Decrypt(sk, ctXOR2, &res1);

    std::cout << "Result of encrypted computation gives sum = " << res1 << std::endl;
    sumcarry.push_back(res1);

    cc.Decrypt(sk, ctXOR3, &res1);

    std::cout << "Result of encrypted computation gives carry = " << res1 << std::endl;
    sumcarry.push_back(res1);

    return sumcarry;
    // // Compute (NOT 1) = 0
    // auto ct2Not = cc.EvalNOT(ct2);

    // // Compute (1 AND (NOT 1)) = 0
    // auto ctAND2 = cc.EvalBinGate(AND, ct2Not, ct1);

    // // Computes OR of the results in ctAND1 and ctAND2 = 1
    // auto ctResult = cc.EvalBinGate(OR, ctAND1, ctAND2);

    // Sample Program: Step 5: Decryption

    //LWEPlaintext result;

    // cc.Decrypt(sk, ctResult, &result);

    //std::cout << "Result of encrypted computation of (13 AND 11) OR (1 AND (NOT 1)) = " << result << std::endl;
}

std::vector<bool> generateBinary(int size) {
    std::vector<bool> result;
    /*
      Insert elements into result
    */
    bool digit;
    for (int i = 0; i < size; i++) {
        std::cout << "Enter only 0 or 1: ";

        std::cin >> digit;
        result.push_back(digit);
    }
    return result;
}
int main() {
    // const int size = 2;
    // bool sum[size + 1];
    int size1, size2;
    std::cout << "Enter the size of the first binary vector: ";
    std::cin >> size1;
    std::vector<bool> booleanArray = generateBinary(size1);

    std::cout << "The first binary vector: \n";
    for (int i = 0; i < size1; i++) {
        std::cout << booleanArray[i];
    }
    std::cout << std::endl;
    std::cout << "Enter the size of the second binary vector: ";
    std::cin >> size2;
    std::vector<bool> booleanArray1 = generateBinary(size2);

    std::cout << "The Second binary vector: \n";
    for (int i = 0; i < size2; i++) {
        std::cout << booleanArray1[i];
    }
    std::cout << std::endl;

    int maxSize = (size1 >= size2) ? size1 : size2;

    std::cout << "\nThe maximum of the size of two vectors is: " << maxSize;

    if (size1 < maxSize) {
        std::vector<bool> temp(maxSize - size1, 0);
        temp.insert(temp.end(), booleanArray.begin(), booleanArray.end());
        booleanArray = temp;
        cout<<"The first vector after transforming to the maximal length is as follows\n";
        for (int i = 0; i < maxSize; i++) {
            std::cout << booleanArray[i];
        }

        std::cout << std::endl;
    }
    else if (size2 < maxSize) {
        std::vector<bool> temp(maxSize - size2, 0);
        temp.insert(temp.end(), booleanArray1.begin(), booleanArray1.end());
        booleanArray1 = temp;
        cout<<"The second vector after transforming to the maximal length is as follows\n";
        for (int i = 0; i < maxSize; i++) {
            std::cout << booleanArray1[i];
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Both arrays are of same length :)\n";
    }

    bool carry = 0;

    cout << "\n\nWe shall compute sum and carry of the " << maxSize << "-th digit of two binaries\n";
    vector<bool> sumcarry = adder(booleanArray[maxSize - 1], booleanArray1[maxSize - 1], carry);
    vector<bool> finalresult;
    finalresult.push_back(sumcarry[0]);
    carry = sumcarry[1];

    // Access and print elements of the boolean array
    for (int i = maxSize - 2; i >= 0; i--) {
        cout << "\n\nWe shall compute sum and carry of the " << i + 1 << "-th digit of two binaries\n";
        // std::cout << booleanArray[i] <<booleanArray[i] <<std::endl;
        sumcarry = adder(booleanArray[i], booleanArray1[i], carry);
        finalresult.push_back(sumcarry[0]);
        carry = sumcarry[1];
    }
    // we shall reverse the final result to get the actual sum of two binaries

    std::reverse(finalresult.begin(), finalresult.end());
    std::cout << "\n\nWe are going to display the final result now of the sum: \n";
    if (carry == 1) {
        std::cout << carry << " ";
        for (bool i : finalresult) {
            std::cout << i << " ";
        }
    }
    else {
        for (bool i : finalresult) {
            std::cout << i << " ";
        }
    }

    std::cout << "\n\nWe are going to display the final carry now: " << carry << std::endl;
    return 0;
}
