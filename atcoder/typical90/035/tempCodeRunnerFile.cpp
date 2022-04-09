{
      auto [_, next] = v[i];
      while (hld.up[st.top()] >= hld.up[next]) {
        st.pop();
      }
      aG.add_edge(st.top(), next);
      st.push(next);
    }