
    for (auto b: div) {
      if (b < a) continue;
      if (K / b / a < b) continue;
      if (K % (a * b) == 0 && K / (a * b) >= b) ans++;
    }
  }