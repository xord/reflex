# -*- coding: utf-8 -*-


%w[xot rays reflex]
  .map  {|s| File.expand_path "../../../#{s}/lib", __FILE__}
  .each {|s| $:.unshift s if !$:.include?(s) && File.directory?(s)}

require 'reflex'


win = Reflex::Window.new do
  set :title, "Shader Sample"
  set :frame, 100, 100, 300, 300

  start  = Time.now.to_f
  shader = Reflex::Shader.new <<-END
    uniform vec2 resolution;
    uniform float time;
    void main ()
    {
      vec2 pos = gl_FragCoord.xy / resolution;
      gl_FragColor = vec4(pos, float(mod(time, 1.0)), 1);
    }
  END

  on :draw do |e|
    e.painter.push do
      attach shader, resolution: bounds.size.to_a, time: Time.now.to_f - start
      rect *bounds.to_a
    end
  end

  on :update do
    redraw
  end
end


Reflex.start name: "Shader Sample" do
  win.show
end
